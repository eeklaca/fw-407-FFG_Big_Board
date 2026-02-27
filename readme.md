# fw-407-FFG_Big_Board - Custom rusEFI Firmware

Welcome to the official repository for the **fw-407-FFG_Big_Board** custom firmware, based on the highly capable open-source [rusEFI](https://rusefi.com/) engine management system.

## 📝 Overview
This repository contains the customized firmware, configuration files, and documentation required to run rusEFI perfectly on the **FatFish Garage RusEFI Big Board** custom hardware board. 

FFG Big Board is a siple board ECU for up to 8 cylinder engines, with optional DBW function. It have 2 pcs 2x25 pin header connector to connect a mother board.

## ⚙️ Hardware Specifications
This custom firmware is configured to work with the following hardware specs:
* **Microcontroller:** STM32F407
* **Inputs:** 4x VR/Hall sensors, MAP, TPS, CLT, IAT, 6x analog inputs, 6x digital inputs
* **Outputs:** 8x Ignition, 8x Injection, VVT control, Optional DBW, FAN control, Tachometer output, etc
* **Communication:** USB
* **Other specific features:** Onboard wideband controller for LSU 4.9

## 🚀 Features
* Full compatibility with **rusEFI console** and **TunerStudio**.
* Custom pinout configuration specifically tailored for the FFG Mini Big Board.

## 🛠️ Installation & Flashing
To flash this custom firmware to your board, please follow these steps:
1. Download the latest compiled binary from the [Releases]([(https://github.com/eeklaca/fw-407_FFG_Big_Board/releases])page.
2. Connect your board via ST-Link ot USB.
3. Use the RusEFI console to update the firmware

## 📄 License
This project is licensed under the [GPL-3.0 License](LICENSE). 
*Note: Since this is based on rusEFI, it inherently inherits the GPLv3 open-source license structure.*
