# IR-Controlled 7-Segment Display

This project uses an IR remote to control a 7-segment display, lighting up the correct digit based on the number button pressed. It was built using an Arduino Uno and leverages the `IRremote` and `SevSeg` libraries for IR signal decoding and display control.

## How It Works

When a number key (0–9) is pressed on the IR remote, the receiver module detects the signal and passes it to the Arduino. The code matches the received IR signal to a predefined hexadecimal code, and then updates the 7-segment display to show the corresponding number.

To build this, I:
- Used the `IRremote` library to read input from the remote.
- Used the `SevSeg` library to control the 7-segment display.
- Mapped each IR signal to a digit using a `switch` statement.

### Example Behavior

- Press `1` on the remote → the display shows `1`
- Press `5` on the remote → the display shows `5`
- And so on for digits 0–9

## Learning Phase

Before writing the final code, I created a separate sketch to read the raw hexadecimal values sent by each button on the IR remote. These values were printed to the Serial Monitor, allowing me to map each button to the correct hex code in the `switch` block of the final program.

## Circuit Setup

### Components
- Arduino Uno
- IR receiver (connected to digital pin 12)
- Common cathode 7-segment display
- 8 jumper wires (one for each segment: A–G + decimal point)
- 8 current-limiting resistors (220Ω recommended)
- Breadboard and jumper wires
- USB cable for power and programming

### Wiring
- Segment pins on the 7-segment display were connected to digital pins 2 through 9 on the Arduino.
- The common cathode pin was connected to GND.
- Each segment had a current-limiting resistor.
- The IR receiver was connected to 5V, GND, and digital pin 12 (for data).
- I enabled built-in LED blinking feedback to visually confirm IR signal reception.

## Libraries Used

- [`IRremote`](https://github.com/Arduino-IRremote/Arduino-IRremote): For receiving and decoding IR signals.
- [`SevSeg`](https://github.com/DeanIsMe/SevSeg): For driving the 7-segment display.

## Features

- Displays digits 0–9 on a 7-segment display using an IR remote
- Accurate decoding of remote signals via hex code mapping
- Easy to expand for additional functions or multi-digit displays

## Future Improvements

- Add more remote button mappings for additional features
- Expand to multiple digits using display multiplexing
- Store the last number displayed using EEPROM

