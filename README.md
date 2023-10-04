# Firmware Repository for Teensy 4.1

Welcome to the firmware repository for the Teensy 4.1 microcontroller. This repository contains firmware code designed to run on the Teensy 4.1 using the Arduino framework. The recommended development environment is PlatformIO IDE on Visual Studio Code.

## Getting Started

### Prerequisites

- **Microcontroller**: Teensy 4.1
- **Development Environment**: [PlatformIO IDE](https://platformio.org/platformio-ide) for Visual Studio Code
- **Framework**: Arduino

### Setting Up PlatformIO IDE

If you're new to PlatformIO, follow the steps below to set it up:

1. **Install PlatformIO IDE**: Download and install PlatformIO IDE for Visual Studio Code. If you're unsure how to do this, refer to the screenshot.
   
   ![PlatformIO Installation Step 1](/doc/00_PlatformIO.PNG)

2. **Configure PlatformIO IDE**: After installation, you need to install the Teensy platform. Search under Embedded Platforms for "Teensy".

   ![PlatformIO Configuration Step 2](/doc/01_PlatformIO.PNG)

3. **Import a Project**: Once PlatformIO IDE is set up, you can import a project.

   ![PlatformIO Project Import Step 3](/doc/02_PlatformIO.PNG)

4. **Build and Upload**: After importing, you can build and upload the firmware to your Teensy 4.1 microcontroller (press the allow that is pointing to the right).

   ![PlatformIO Build and Upload Step 4](/doc/03_PlatformIO.PNG)

5. **Check if Upload was successful**:  Make sure that the console shows the following output.
    ```
    Processing teensy41 (platform: teensy; framework: arduino; board: teensy41)
    CONFIGURATION: https://docs.platformio.org/page/boards/teensy/teensy41.html
    PLATFORM: Teensy (4.18.0) > Teensy 4.1
    HARDWARE: IMXRT1062 600MHz, 512KB RAM, 7.75MB Flash
    DEBUG: Current (jlink) External (jlink)
    PACKAGES:
    - framework-arduinoteensy @ 1.158.0 (1.58)
    - tool-teensy @ 1.158.0 (1.58)
    - toolchain-gccarmnoneeabi-teensy @ 1.110301.0 (11.3.1)
    LDF: Library Dependency Finder -> https://bit.ly/configure-pio-ldf
    LDF Modes: Finder ~ chain, Compatibility ~ soft
    Found 92 compatible libraries
    Scanning dependencies...
    No dependencies
    Building in release mode
    Compiling .pio\build\teensy41\src\Blink.cpp.o
    Linking .pio\build\teensy41\firmware.elf
    Checking size .pio\build\teensy41\firmware.elf
    Building .pio\build\teensy41\firmware.hex
    Configuring upload protocol...
    AVAILABLE: jlink, teensy-cli, teensy-gui
    CURRENT: upload_protocol = teensy-gui
    Uploading .pio\build\teensy41\firmware.hex
    ============================= [SUCCESS] Took 2.29 seconds =============================
    ```

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

- [Teensy 4.1 Official Documentation](https://www.pjrc.com/store/teensy41.html)
- [PlatformIO Documentation](https://docs.platformio.org/en/latest/)

