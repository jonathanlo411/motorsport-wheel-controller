<img src="/assets/logos/full.png" alt="team spiral racing logo" width="400"/>

[![PlatformIO Build](https://github.com/jonathanlo411/motorsport-wheel-controller/actions/workflows/build.yaml/badge.svg)](https://github.com/jonathanlo411/motorsport-wheel-controller/actions/workflows/build.yaml)
<a href="https://github.com/jonathanlo411/motorsport-wheel-controller/releases"><img src="https://img.shields.io/github/v/release/jonathanlo411/motorsport-wheel-controller?color=f56827"></a>
<a href="https://github.com/jonathanlo411/motorsport-wheel-controller/blob/main/LICENSE"><img src="https://img.shields.io/github/license/jonathanlo411/motorsport-wheel-controller"></a>

# Motorsport Wheel Controller
A steering wheel microcontroller system to control various features of the car designed with motorsport in mind. This system is used in place of standalone ECUs ([MoTeC](https://www.motec.com.au/), [Haltech](https://www.haltech.com/)) when they are not required or desired.

> NOTE: If you are on forced induction or have an engine swap, Team Spiral Racing (and me Jonathan Lo) highly recommend switching to a standalone ECU instead of using this system.

## Design
This system is made up of two microcontrollers, one in the steering wheel (`wheel/`) and one in the car (`controller/`). Any microcontroller should technically work but this system is designed with Espressif ESP32 Dev boards in mind. In order to work, 5V power need to be supplied to the system. In most automative applications, this can be done via a ignition fuse tap connected to a 12V -> 5V buck converter. 

### Wheel
A micro controller will be placed inside the steering wheel. Inputs are handled by an array of button switches wired to the GPIO pins of the microcontroller. To communicate to the controller, two GPIO pins are dedicated to sending CAN messages via a CAN transceiver connected to a GX16-4 connector.

### Controller
A secondary micro controller will be placed inside the car. GPIO pins are dedicated to connecting the car's internal switch system. Examples include but are not limited lights, cruise control, and radio. Communication is done over CAN messages and two GPIO pins are dedicated to a CAN transceiver connecting to a GX16-4 connector.

### Communication
As stated above, communucation betwenn the two microcontroller is handled over a CAN protocol. Two GPIO ports are dedicated on each are dedicated to TX/RD (CANH/CANL) and are connected to a CAN transceiver; Currently the system is designed to use SN65HVD230's. These CAN transceviers are then wired to GX16-4 connectors where they connect to the harness.

A simple harness with 4 wires inside runs between the two connectors to enable wired connection. This wire is coiled and be stretched to ensure it does not get tangled with the steering wheel/hub during large/tight turns. The other two wires are 5V power and ground.

## License
This project is licensed under the MIT License. See `LICENSE` for more information.
