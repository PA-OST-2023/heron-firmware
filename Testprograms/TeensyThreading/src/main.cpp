#include <SD.h>
#include <MTP_Teensy.h>
#include <TeensyThreads.h>
#include <console.h>

volatile int count = 0;
void thread_func(int data)
{
  while(1) count += data;
}

void setup()
{
  console.begin();
  MTP.begin();

  if (SD.begin(BUILTIN_SDCARD))
  {
    MTP.addFilesystem(SD, "SD Card");
    console.ok.println("[MAIN] Added SD card using built in SDIO, or given SPI CS");
  }
  else
  {
    console.warning.println("[MAIN] No SD Card");
  }
  console.ok.println("[MAIN] Setup done");

  threads.addThread(thread_func, 1);
}

void loop()
{
  static uint32_t t = 0;
  if (millis() - t > 1000)
  {
    t = millis();
    console.log.printf("[MAIN] Time: %d\n", t);
  }

  MTP.loop();
}