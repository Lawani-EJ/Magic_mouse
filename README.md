# Magic-Mouse (Arduino Device to Assist the Blind in Taking Examination on a Webpage)
### Our Overview 
The project mainly focused on building an Arduino-based system designed to assist visually impaired students during examinations was conducted on a webpage.
By integrating hardware components like Arduino Uno, buttons, capacitors, and jumper wires, the hardware system collects user input and communicates with a web server, enabling blind users to interact with online exam platforms more efficiently.
This project is called `MagicMouse` which is a Node.js project that enables real-time communication between a server and clients using WebSockets. It also integrates serial port communication, making it useful for hardware-related applications.

## Table Of Contents
- Introduction
- System Specfications
- Materials Used
- System Description
    - Hardware Setup
    - Arduino code
    - Web Server Setup
- Conclusion.

## 🛠 System Specifications
The system specifications describe the complete set of hardware components and software functionality and purpose. It includes a technical overview of the system units and their usage.
The specifications for the primary hardware components are listed below;

### Specification List
- Laptop (with Arduino IDE and Serial Port support)
- Arduino Uno board
- Breadboard
- Jumper wires
- Buttons
- Capacitors
- Soldering Iron

# Brief description of the materials used:
## Availability of a laptop that supports Arduino uno and serial port connection:
A laptop serves as the command center for your Arduino adventures. It houses the Arduino IDE (Integrated Development Environment), a software program where you write code (instructions) for your Arduino board. The laptop also facilitates the serial port connection, a communication channel that allows you to upload code from your computer to the Arduino. 

- The laptop minimum specifications would be:
    - Minimum Intel Core i3 or AMD Ryzen 3 (dual core) processor
    - Minimum 4 GB RAM
    - USB Port: You'll need at least one USB port to connect your Arduino board to the laptop.
    - Minimum 128 GB Hard Disk Drive (HDD) for faster loading times and overall better performance.

## Arduino uno: 
- The Arduino Uno, a name synonymous with beginner-friendly electronics, is much more than just a board. It's the beating heart of countless creative projects, a mini computer specifically designed to bridge the gap between the digital world of code and the physical world of sensors, lights, and motors.
- Imagine it as a tiny maestro, effortlessly reading data from temperature gauges or light sensors, then translating that information into actions.
- Need to control the dazzling dance of LEDs or the precise movements of a small motor?
- The Arduino Uno displayed programmed with your instructions, becomes the conductor, bringing your vision to life.
- Its user-friendly design makes it ideal for both seasoned electronics enthusiasts and absolute beginners.
- The vast online community and countless resources provide a treasure trove of tutorials, code examples, and troubleshooting guides, ensuring a smooth learning curve.
- Whether you're tinkering with basic circuits or venturing into complex projects, the Arduino Uno serves as a solid foundation for your exploration into the exciting world of electronics. 

## Breadboard:
- The breadboard helps avoid messy wires and frustrating connections; the breadboard is the solution that helps reusable platform bristling with a grid of holes. 
- Beneath this surface lies the magic: a network of metal strips cleverly connecting the holes.
- This allows you to effortlessly plug electronic components together without needing to break out the soldering iron.
- It's like a construction zone for circuits, perfect for experimenting and building prototypes.
- Even with a need to swap a sensor is not a problem as it is as easy as to just pop it out and try a different one. Feeling adventurous with a new configuration? The breadboard encourages quick and easy circuit modifications.
- With the breadboard as your canvas, bringing your ideas to life becomes a breeze, allowing you to test, build, and refine your electronics projects with ease.

## JumpWires:
Jumper wires are simply the electrical bridges that bring your circuit to life. These short, flexible wires are the workhorses of the breadboard, each boasting connectors at both ends for seamless integration. This flexibility is crucial for circuit organization. By assigning specific colors to different voltage levels or functions, you can quickly identify potential issues immediately. It is vital for connecting various components on your breadboard. These short, flexible wires come with connectors at both ends, allowing you to easily plug them into the breadboard holes.

## Soldering iron:
The soldering iron is a tool for tasking connections While breadboards are perfect for prototyping, for projects destined for the long haul, the soldering iron steps up to the plate. By applying heat, the solder flows, joining components together electrically and physically. This soldered connection offers a far more durable solution than the temporary connections of a breadboard.
While breadboards are excellent for prototyping, for permanent connections, a soldering iron comes into play. This tool melts a metal alloy called solder, creating strong electrical and physical bonds between components. Soldering offers a more durable solution for building your electronics projects.

# System Description
 
<!--
## Included Features
1. Express.js: Handles HTTP requests and serves as the backend framework.

2. CORS: Enables cross-origin requests.

3. SerialPort: Facilitates communication with serial devices.

4. Socket.io: Enables real-time bidirectional communication between the server and clients.

# Installation Guide
### Prerequisites
- Install Node.js (version 14 or later recommended)

- Steps to Install
    Clone this repository:
    ```bash
    git clone <https://github.com/Lawani-EJ/Magic_mouse>
    cd magicmouse
    ```
- Install dependencies:
```bash
npm install
```

## Dependencies
1. The project relies on the following Node.js modules:

2. Express (^4.21.2) – Lightweight web framework.

3. CORS (^2.8.5) – Enables cross-origin requests.

4. SerialPort (^13.0.0) – Used for reading/writing to serial devices.

5. Socket.io (^4.8.1) – Enables real-time WebSocket communication.

6. Socket.io-client (^4.8.1) – The client-side library for WebSocket connections.


## Run the Project

- Start the server:
```bash
node testSerial.js
```
- The server will now listen for serial input and handle WebSocket communication.

## Contribution
Feel free to fork and contribute to this project by creating pull requests.
-->
