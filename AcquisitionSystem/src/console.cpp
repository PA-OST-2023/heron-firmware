/******************************************************************************
* file    console.cpp
*******************************************************************************
* brief   Wrapper for Serial Debugging (threadsafe, buffered, colorized, etc.)
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2022-08-02
*******************************************************************************
* MIT License
*
* Copyright (c) 2022 Crelin - Florian Baumgartner
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell          
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
******************************************************************************/

#include "console.h"

FLASHMEM bool Console::begin(void)
{
  if(type == USBCDC_t)
  {
    (*(usb_serial_class*)&stream).begin(0);
  }
  else return false;
  return initialize();
}

FLASHMEM bool Console::begin(unsigned long baud, uint32_t config)
{
  if(type == HardwareSerial_t)
  {
    (*(HardwareSerial*)&stream).begin(baud, config);
  }
  else return false;
  return initialize();
}

FLASHMEM bool Console::initialize(void)
{
  ringBuffer = (char*) malloc(QUEUE_BUFFER_LENGTH);
  if(ringBuffer == nullptr) return false;
  bufferAccessSemaphore = xSemaphoreCreateMutex();
  initialized = true;
  xTaskCreate(writeTask, "task_consoleWrite", 4096, this, 2, &writeTaskHandle);
  xTaskCreate(interfaceTask, "task_consoleIface", 256, this, 2, NULL);
  return true;
}

FLASHMEM void Console::end(void)
{
  initialized = false;
}

void Console::writeTask(void *pvParameter)
{
  Console* ref = (Console*)pvParameter;

  while(ref->initialized)
  {
    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);          // Wait on notification for data in buffer or console opened
    if(ref->streamActive)
    {
      if(xSemaphoreTake(ref->bufferAccessSemaphore, portMAX_DELAY))
      {
        if(ref->readIdx < ref->writeIdx)              // Regular case, no wrap around needed
        {
          ref->stream.write((const uint8_t*) ref->ringBuffer + ref->readIdx, ref->writeIdx - ref->readIdx);
        }
        else if(ref->readIdx > ref->writeIdx)         // Need to send buffer in two parts (ReadIdx to End | 0 to WriteIdx)
        {
          ref->stream.write((const uint8_t*) ref->ringBuffer + ref->readIdx, QUEUE_BUFFER_LENGTH - ref->readIdx);
          ref->stream.write((const uint8_t*) ref->ringBuffer, ref->writeIdx);
        }
        ref->readIdx = ref->writeIdx;
        xSemaphoreGive(ref->bufferAccessSemaphore);
      }
    }
  }
  vTaskDelete(NULL);
}

void Console::interfaceTask(void *pvParameter)
{
  Console* ref = (Console*)pvParameter;

  TickType_t interfaceTimer = 0;
  TickType_t enabledTimer = 0;
  bool enabledOld = false, enabledDelayed = false;
  bool interfaceOld = false, interfaceDelayed = false;
  bool streamActiveOld = false;
  while(ref->initialized)
  {
    TickType_t task_last_tick = xTaskGetTickCount();

    if(ref->enabled && !enabledOld)
    {
      enabledTimer = xTaskGetTickCount() + CONSOLE_ACTIVE_DELAY;
    }
    enabledOld = ref->enabled;
    enabledDelayed = (xTaskGetTickCount() > enabledTimer) && ref->enabled;

    if(ref->getInterfaceState() && !interfaceOld)
    {
      interfaceTimer = xTaskGetTickCount() + INTERFACE_ACTIVE_DELAY;
    }
    interfaceOld = ref->getInterfaceState();
    interfaceDelayed = (xTaskGetTickCount() > interfaceTimer) && ref->getInterfaceState();

    ref->streamActive = enabledDelayed && interfaceDelayed;
    if(ref->streamActive && !streamActiveOld)
    {
      ref->printStartupMessage();
      vTaskDelay(pdMS_TO_TICKS(10));                        // Make sure that startup message is printed befor everything else
      xTaskNotifyGive(ref->writeTaskHandle);                // Send signal to update task (for sending out data in queue buffer)
    }
    if(!ref->streamActive && streamActiveOld)               // Detect if console has been closed
    {
      ref->stream.flush();
      ref->stream.clearWriteError();
    }
    streamActiveOld = ref->streamActive;

    vTaskDelayUntil(&task_last_tick, pdMS_TO_TICKS(1000 / INTERFACE_UPDATE_RATE));
  }
  vTaskDelete(NULL);
}

FLASHMEM size_t Console::write(const uint8_t *buffer, size_t size)
{
  if(size == 0) return 0;
  if(xSemaphoreTake(bufferAccessSemaphore, portMAX_DELAY))
  {
    size_t free;
    size = min(size, (size_t) QUEUE_BUFFER_LENGTH - 1);
    if(writeIdx + size <= QUEUE_BUFFER_LENGTH)
    {
      memcpy((uint8_t*) ringBuffer + writeIdx, buffer, size);
      free = QUEUE_BUFFER_LENGTH - (writeIdx - readIdx);
    }
    else
    {
      size_t firstPartSize = QUEUE_BUFFER_LENGTH - writeIdx;
      memcpy((uint8_t*) ringBuffer + writeIdx, buffer, firstPartSize);
      memcpy((uint8_t*) ringBuffer, buffer + firstPartSize, size - firstPartSize);
      free = readIdx - writeIdx;
    } 
    writeIdx = (writeIdx + size) & (QUEUE_BUFFER_LENGTH - 1);
    if(size > free)
    {
      readIdx = (readIdx + (size - free)) & (QUEUE_BUFFER_LENGTH - 1);
    }

    xSemaphoreGive(bufferAccessSemaphore);
    xTaskNotifyGive(writeTaskHandle);               // Send signal to update task (for sending out data)
    return size;
  }
  return 0;
}

FLASHMEM void Console::printTimestamp(void)
{
  int h = min(millis() / 3600000, 99);
  int m = (millis() / 60000) % 60;
  int s = (millis() / 1000) % 60;
  int ms = millis() % 1000;
  printf("[%02d:%02d:%02d.%03d] ", h, m, s, ms);
}

FLASHMEM void Console::printStartupMessage(void)
{
  stream.print(CONSOLE_CLEAR);
  stream.print(CONSOLE_COLOR_BOLD_CYAN CONSOLE_BACKGROUND_DEFAULT);
  stream.println("****************************************************");
  stream.println("*                AcquisitionSystem                 *");
  stream.println("*      2023, Florian Baumgartner, Alain Keller     *");
  stream.println("****************************************************");
  stream.println("*                                                  *");      
  stream.println("*                              +%@@#==+++++-.      *");                  
  stream.println("*                            :+.  :==+==:.         *");                  
  stream.println("*                           .+==.::..              *");                  
  stream.println("*                          .*:=--:                 *");                  
  stream.println("*                         .= .====:                *");                  
  stream.println("*                             .=+++-               *");                  
  stream.println("*                               *+#-               *");                  
  stream.println("*                              .*+#-               *");                  
  stream.println("*                         .::--*#**-               *");                  
  stream.println("*                      :+#%%@@*###-=               *");                  
  stream.println("*                    :*@@@@*@#+*+%-:               *");                  
  stream.println("*                  :*%@@@@@@%.=+=+-                *");                  
  stream.println("*                :*##@@@@%%##=%#=-.                *");                  
  stream.println("*              .=**#@@@%%%#@@#%+=:                 *");                  
  stream.println("*            .=#%%%%%####%@@*..*=                  *");                  
  stream.println("*           .*%%%#####*#%@@= .::.                  *");                  
  stream.println("*           +##%####%%*=#%=-:.                     *");                  
  stream.println("*          +*%%%@%#+-+--#-:                        *");                  
  stream.println("*         =##@@%#+--::=*+                          *");                  
  stream.println("*        :%@@%#=.     +*-                          *");                  
  stream.println("*        -@@@*.      .%%:                          *");                  
  stream.println("*        .-:.        .@@=                          *");                  
  stream.println("*                     #*=                          *");                  
  stream.println("*                     *-#                          *");                  
  stream.println("*                     -=+:                         *");                  
  stream.println("*                     :#.#                         *");                  
  stream.println("*        ... ..    ..:-@=@+--=-.... ..             *");                  
  stream.println("*       ...::...:::-=+++*###*=--.:::::.            *");                  
  stream.println("****************************************************");
  stream.println(CONSOLE_LOG);
}


#ifndef USE_CUSTOM_CONSOLE
  Console console(Serial, true);
#endif
