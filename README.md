# Arduino

Arduino programs for different applications

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

* Arduino IDE
* Arduino Board
* A computer with OSX, Windows, Linux

### Installing

Install the last stable version of Arduino, you can download it from this page:

*   [Arduino](https://www.arduino.cc/en/Main/Software)

## Test your board

Open Arduino IDE and upload the next example:
```
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
```
This is one simple example to blink a led that contains the Arduino Uno board in the pin number 13, if the small led attached to pin number 13 is blinking your board is ready.

## Also you can use the next IDE to build programs:

* [Arduino Online IDE](https://create.arduino.cc/editor)
* [PlataformIO](http://platformio.org/get-started)

### To use the last one you must install first ATOM:

* [Atom](https://atom.io/)

## Contributing

Please read [CONTRIBUTING.md](https://github.com/totovr/Processing/blob/master/CONTRIBUTING.md) for details of the code of conduct, and the process for submitting pull requests to us.

## Versioning

I use [SemVer](http://semver.org/) for versioning.

## Authors

Antonio Vega Ramirez:

* [Github](https://github.com/totovr)
* [Twitter](https://twitter.com/SpainDice)

## License

This project is licensed under The MIT License (MIT) - see the [LICENSE.md](https://github.com/totovr/Arduino/blob/master/LICENSE.md) file for details
