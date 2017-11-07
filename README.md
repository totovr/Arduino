# esp32

Installation instructions for Mac OS

1.- Install latest Arduino IDE from arduino.cc

2.- Open Terminal and execute the following command (copy->paste and hit enter):

    mkdir -p ~/Documents/Arduino/hardware/espressif && \
    cd ~/Documents/Arduino/hardware/espressif && \
    git clone https://github.com/espressif/arduino-esp32.git esp32 && \
    cd esp32 && \
    git submodule update --init --recursive && \
    cd tools && \
    python get.py
    
Inside the folder "hardware/espressif/esp32" that you have create run:

    git submodule update --init --recursive 
    
If in the BLE doesn't appear the files after run this command you can directly copy from Master Branch and paste it inside    of BLE folder
  
    https://github.com/nkolban/ESP32_BLE_Arduino/tree/cb1ab4ea76af17d347cdadcc003d1fe53af12aa7
  
  # This version just run in Python 2.7
  
If you get the error below. Install the command line dev tools with xcode-select --install and try the command above again:
  
    xcrun: error: invalid active developer path (/Library/Developer/CommandLineTools), 
    missing xcrun at: /Library/Developer/CommandLineTools/usr/bin/xcrun
    xcode-select --install

3.- Restart Arduino IDE 

Credits to https://github.com/espressif/arduino-esp32
