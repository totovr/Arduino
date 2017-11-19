# Arduino repository

Arduino programs for different applications

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

* Arduino IDE
* Arduino Board
* OSX, Windows, Linux

### Installing

Install the Arduino IDE, you can download it from this page:

    https://www.arduino.cc/en/Main/Software

## Test your board

Open Arduino IDE and upload one of the examples, this is one simple example to blink a led that contains a Arduino Uno in the pin number 13:

    void setup() {
      // initialize digital pin LED_BUILTIN as an output.
      pinMode(LED_BUILTIN, OUTPUT);
    }

    // the loop function runs over and over again forever
    void loop() {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(1000);                       // wait for a second
    }


### If the small led attached to pin number 13 is blinking your board is ready

## Also you can use the next IDE to build programs:

* [Arduino Online IDE](https://create.arduino.cc/editor)
* [PlataformIO](http://platformio.org/get-started)

### To use the last one you must install first ATOM:

* [Atom](https://atom.io/)

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available.

## Authors

* Antonio Vega Ramirez - [PurpleBooth](https://github.com/totovr)

## License

This project is licensed under CC License - see the [LICENSE.md](https://creativecommons.org/licenses/by/4.0/) file for details
