##### HC-05 Example

This program use a HC-05 module connected to an Arduino Uno to control from the computer the board via Bluetooth 

###### Setup in Raspberry Pi 3 Linux ubuntu MATE

##### Procedure

* Connect the HC-05 module to the Arduino board

|HC-05 PIN|Arduino PIN|
|:-------:|:---------:|
| VCC     |     5V    |
| GND     |     GND   |   
| Tx      |     10    |    
| RX      |     11    |   

* Open BLE_Arduino program
* Download Putty
      sudo apt-get install putty
* Upload the BLE_Arduino program in the board
* Connect the HC-05 module to the computer

###### In this step check which is the port that the HC-05 is using, example rfcomm0

* Open Putty

<img src="https://github.com/totovr/Arduino/blob/master/SH/HC-05/BLE_Arduino/putty.png" width="450">

* Connect with the Serial option to the port that is assigned to the Bluetooth module
