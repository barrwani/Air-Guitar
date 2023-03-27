# Air-Guitar
Project created for EG-UY 1004 Introduction to Engineering and Design's Rapid Assembly and Design (RAD) Semester-Long Design Project.

The Air Guitar A fully functioning MIDI Guitar which utilises Capacitive Touch Sensor technology and the Arduino UNO to output MIDI data to a DAW.

The prototype was presented at the end of semester RAD showcase alongside 6 other teams, selected out of 66 total groups.

A demo can be found at the following link: https://www.youtube.com/watch?v=r-h1myEDbb0

The Air Guitar's Workflow works by utilising a Serial to MIDI bridge called Hairless MIDI (https://projectgus.github.io/hairless-midiserial/) alongside a virtual MIDI port software called loopMIDI (https://www.tobias-erichsen.de/software/loopmidi.html) in order to send MIDI data from the Arduino to a DAW.

![Flow Chart](https://user-images.githubusercontent.com/59224547/227822123-f987106e-526c-4bcf-bfb4-4dc2a9d48f9b.jpeg|500)


The circuitry involves a 'common send' pin which is connected to all sensors, as well as a 2MΩ resistor for each individual sensor. This allows the sensors to measure the electrical capacitance of a user's finger upon contact when used in combination with the CapactiveSensor Library (https://github.com/PaulStoffregen/CapacitiveSensor).


![Circuit Diagram](https://user-images.githubusercontent.com/59224547/227822723-c28f9dfa-b48e-4d13-b3ff-c7b154a67e5b.png)


The construction of the instrument is sturdy and light, using sheets of wood cut in the shape of a guitar alongside spacer segments to reduce weight and material costs, as well as allowing for ease of maintenance and access to the circuitry if necessary.

![CAD Model](https://user-images.githubusercontent.com/59224547/227823453-a779e33b-d81f-4b35-be59-0225d275cd91.png)
