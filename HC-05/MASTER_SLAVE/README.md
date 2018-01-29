## HC-05 Example

This program pair two HC-05 module to blink one led everytime that a bottom is press

###### Setup in Raspberry Pi 3 Linux ubuntu MATE

##### Requirements

* 2 Modules HC-05
* 2 Arduino Board
* 1 led
* 1 push bottom

##### Procedure

* Connect the HC-05 module to the Arduino board

|HC-05 PIN|Arduino PIN|
|:-------:|:---------:|
| VCC     |     5V    |
| GND     |     GND   |   
| TX      |     TX    |    
| RX      |     RX    | 
| EN      |    3.3V   | 

### Slave Configuration

* Before turn on the Arduino keep pressed the bottom of the HC-05 module, after turn it on the light will be blinking slower,
this means that you are in AT-COMMAND mode.

* Open an Arduino empty file and upload it to the board

* Open the serial terminal and type:

      AT

  It must return:

      OK

###### Ensure to select “BOTH NL & CR”  & Baud Rate as 9600 at the bottom of the serial monitor, in some cases you have to setup the Baud Rate at 38400.This is very important as the Bluetooth module HC05 expects both Carriage Return and Line Feed after every AT command.

* Check the speed by:

      AT+ UART?
      
###### Default baud rate is 9600 
  
* To change the speed tape the next command, where Param is baud rate, Param2 is stop bit, Param3 is parity bit.
      
      AT+UART=<Param>,<Param2>,<Param3>
  
* Lets check the name of the module typing:

      AT+NAME?

  Also you can change the name as you like with:

      AT+NAME="NAME THAT YOU WANT"

* The password by default is  1234, confirm it with:

      AT+PSWD?

* The ROLE of the module can be known by typing:  

      AT+ROLE?

  You can change it by:

      AT+ROLE=0    

  ###### 0 for SLAVE & 1 for Master. Leave it as 0 as we want this module to be SLAVE.

#### **You should know the Address of this module to make it PAIR with another.**

* To know the address of this module type the next command:

      AT+ADDR?  

  Note that the Address is showed like this:

      14:2:110007

  While using this address in AT commands you should replace the **colon** with a **comma**, like this:

      14,2,110007

  **Remember to write this address we will use it later**

* Turn off the Arduino and turn it on Again

###### Again provide the power to see STATUS LED on the module blinking fast indicating that it is looking for a PAIR.

### Master Configuration

* Before turn on the Arduino keep pressed the bottom of the HC-05 module, after turn it on the light will be blinking slower,
this means that you are in AT-COMMAND mode.

* Open an Arduino empty file and upload it to the board

* Open the serial terminal and type:

      AT

  It must return:

      OK

###### Ensure to select “BOTH NL & CR”  & Baud Rate as 9600 at the bottom of the serial monitor, in some cases you have to setup the Baud Rate at 38400.This is very important as the Bluetooth module HC05 expects both Carriage Return and Line Feed after every AT command.

* Lets check the name of the module typing:

      AT+NAME?

  Also you can change the name as you like with:

      AT+NAME="NAME THAT YOU WANT"

* The password by default is  1234, confirm it with:

      AT+PSWD?

* If you had pair this module before you can use the next command to forgot the last device:

      AT+RMAAD  

  this will release the module from any previous PAIR.

* The ROLE of the module can be known by typing:  

      AT+ROLE?

  You can change it to **Master** typing:

      AT+ROLE=1    

  ###### 0 for SLAVE & 1 for Master. Leave it as 0 as we want this module to be SLAVE.

* Typing:

      AT+CMODE=1

  Allows to connect you to any address, default is CMODE = 0 which allows connection to only bound address.  

##### Start SPP profile library (needed to do any Bluetooth transmitting/receiving):

* Initialize the SPP Profile library by typing

      AT+INIT  

**If you get ERROR(17) , it means you’ve already issued this command & you can continue ignoring the error.**

**Note that for the next point we will need the address of the SLAVE that you previously write, remember to change the colons to commas**

* We will pair the SLAVE module with the MASTER module typing the next command:

      AT+LINK=<address>

  **Also you can check the AT+BIND command**

* Turn off the Arduino and turn it on Again

###### Again provide the power to see STATUS LED on the module blinking fast indicating that it is looking for a PAIR.

#### If all the process is complete the led of each module must blink slower, this means that the modules are paired

#### Arduino programs

* To be able to use the board with the module remember to change the pins showed in the next table:

|HC-05 PIN|Arduino PIN|
|:-------:|:---------:|
| VCC     |     5V    |
| GND     |     GND   |   
| TX      |     RX    |    
| RX      |     TX    |

**Every time that you upload a program to the board is necessary to disconnect the RX and TX pins of the module with the board**
