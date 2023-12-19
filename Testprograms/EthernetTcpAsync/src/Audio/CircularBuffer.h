/******************************************************************************
* file    CircularBuffer.h
*******************************************************************************
* brief   Custom Circular Buffer implementation
*******************************************************************************
* author  Florian Baumgartner
* version 1.0
* date    2023-12-19
*******************************************************************************
* MIT License
*
* Copyright (c) 2023 ICAI Interdisciplinary Center for Artificial Intelligence
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

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <Arduino.h>
#include <stdexcept>
#include <cstddef>

template<size_t Size>
class CircularBuffer
{
  static_assert(Size % 2 == 0, "Size must be a multiple of 2");
  static_assert(Size > 0, "Size must be greater than 0");

  public:
    CircularBuffer() : head(0), tail(0), bufferSize(0), bufferCapacity(Size), bufferFull(false){}

    ~CircularBuffer() {}

    void write(const uint8_t* data, size_t size) {
        if (size > availableToWrite()) {
            // Handle error or resize logic
            return;
        }

        for (size_t i = 0; i < size; ++i) {
            buffer[tail] = data[i];
            tail = (tail + 1) % Size;
            bufferSize++;
        }

        if (bufferSize == bufferCapacity) {
            bufferFull = true;
        }
    }

    void read(uint8_t* data, size_t size) {
        if (size > availableToRead()) {
            // Handle error
            return;
        }

        for (size_t i = 0; i < size; ++i) {
            data[i] = buffer[head];
            head = (head + 1) % Size;
            bufferSize--;
        }

        bufferFull = false;
    }

    void peek(uint8_t* data, size_t size) {
        if (size > availableToRead()) {
            // Handle error
            return;
        }

        size_t currentHead = head;
        for (size_t i = 0; i < size; ++i) {
            data[i] = buffer[currentHead];
            currentHead = (currentHead + 1) % Size;
        }
    }

    void markBytesRead(size_t size) {
        if (size > bufferSize) {
            // Handle error
            return;
        }

        head = (head + size) % Size;
        bufferSize -= size;

        bufferFull = false;
    }

    void clear() {
        head = tail = bufferSize = 0;
        bufferFull = false;
    }

    size_t availableToRead() const {
        return bufferSize;
    }

    size_t availableToWrite() const {
        return bufferCapacity - bufferSize;
    }

    size_t capacity() const {
        return bufferCapacity;
    }

    bool empty() const {
        return bufferSize == 0;
    }

    bool full() const {
        return bufferFull;
    }

  private:
    uint8_t buffer[Size];
    size_t head;
    size_t tail;
    size_t bufferSize;
    const size_t bufferCapacity;
    bool bufferFull;
};

#endif