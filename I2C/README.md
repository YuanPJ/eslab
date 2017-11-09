# Reading the 3D acceleator value

| RPi 3                | Arduino UNO     |
|----------------------|-----------------|	
| GPIO 2 (pin 3) (SDA) |  Analog 4 (SDA) |
| GPIO 3 (pin 5) (SCL) |  Analog 5 (SCL) |
| GPIO 17              |  Digital 8      |
| GND	                 |  GND            |

## Raspberry Pi side
    $ python i2c-pi-arduino.py

## Arduino side
The arduino side code is named `i2c-pi-arduino.ino` here.
