<p align="center">
    <a href="#" style="display: block;" align="center">
        <img src="https://myschoolportal.net/blog/wp-content/uploads/2024/10/babcock-university-logo.png" alt="sosuke aizen" width="60%" />
    </a>
</p>

<p align="center">
    <a href="#" style="display: block;" align="center">
        <img src="https://cdn-images-1.medium.com/max/280/1*-__XowPJ8-8Q48Q6XODjag@2x.png" alt="sosuke aizen" width="60%" />
    </a>
</p>

# BABCOCK UNIVERSITY FINAL YEAR PROJECT
###  SUBMITTED TO: 
THE DEPARTMENT OF COMPUTER SCIENCE SCHOOL OF COMPUTING AND ENGINEERING SCIENCES BABCOCK UNIVERSITY, ILISAN REMO OGUN STATE, NIGERIA
## Magic-Mouse (An Arduino Device used to Assist the Blind in Taking Examination on a Webpage)
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
### The Hardware Setup
The foundation for data transmission lies in establishing a physical connection between the Arduino and the web server or network device. This involves two steps:
 1. Arduino-Computer Connection: Connect the Arduino to the computer using a USB cable. This connection allows for programming the Arduino and uploading the necessary code.
 2. Arduino-Network Connection: Establish a network connection between the Arduino and the web server or network device using an Ethernet shield or Wi-Fi module. This connection will enable the Arduino     to send data to the web server

### Arduino Code
For the implementation of this project, the Arduino IDE was employed. The Arduino IDE, which was already installed on the machine and was updated to the latest version. the required libraries such as the SPI and Servo were installed. The setup and the code development area were used to compile and verify the code with the forward arrow located at the top left of the Arduino IDE application as illustrated. The Arduino code was executed, compiled and all problems were debugged.

```ino
int buttonCounter = 0; // Stores the count
bool button1Pressed = false; // Prevents multiple increments on one press
bool button2Pressed = false; 
bool button3Pressed = false; // Prevents multiple prints of "repeat" 

void setup() {
  pinMode(2, INPUT_PULLUP); // Button 1 (Increase counter)
  pinMode(3, INPUT_PULLUP); // Button 2 (Print counter)
  pinMode(4, INPUT_PULLUP); // Button 3 (Print "repeat")
  Serial.begin(9600);
}

void loop() {
  // Read button states
  int button1State = digitalRead(2);
  int button2State = digitalRead(3);
  int button3State = digitalRead(4);

  // 🔹 Button 1: Increment counter (Only when pressed)
  if (button1State == LOW && !button1Pressed) {
    delay(50); // Debounce delay
    if (digitalRead(2) == LOW) { // Check again to confirm press
      if (buttonCounter >= 3) { 
        buttonCounter = 4;
      } else {
        buttonCounter++;  
      }
      button1Pressed = true; // Prevents multiple counts on a single press
    }
  }
  if (button1State == HIGH) {
    button1Pressed = false; // Reset when button is released
  }

  // 🔹 Button 2: Print counter OR "next"
  if (button2State == LOW && !button2Pressed) {  
    delay(50); // Debounce delay
    if (digitalRead(3) == LOW) { // Confirm press
      if (buttonCounter > 0) {
        Serial.println(buttonCounter);
        buttonCounter = 0; // Reset only after printing counter
      } else {
        Serial.println("next");
      }
      button2Pressed = true;
    }
  }
  if (button2State == HIGH) {
    button2Pressed = false; // Reset when button is released
  }

  // 🔹 Button 3: Print "repeat" only once per press
  if (button3State == LOW && !button3Pressed) { 
    delay(50); // Debounce delay
    if (digitalRead(4) == LOW) { // Confirm press
      Serial.println("repeat");
      button3Pressed = true;
    }
  }
  if (button3State == HIGH) {
    button3Pressed = false; // Reset when button is released
  }
}
```
The Arduino microcontroller acts as the data collector, responsible for acquiring sensor data, processing information, and transmitting it to the web server. The Arduino code typically encompasses the following:
1. Library Inclusion: Include the necessary libraries for serial communication and web connectivity. These libraries provide the functions and tools for interacting with the hardware and sending data over the network.
2. Data Variable Definition: Define a variable to store the sensor data or button count. This variable will hold the information to be transmitted to the web server.
3. Sensor Data Acquisition: Read the sensor data or button state using appropriate Arduino functions. These functions interact with the connected sensors or buttons to retrieve the current values.
4. Data Conversion: Convert the sensor data or button count into a string format for transmission. Since the web server expects data in text form, converting numerical values to strings ensures compatibility.
5. Data Transmission: Send the string data using the Serial.println() function. This function transmits the converted data over the serial port, establishing a connection with the web server.

### Web server setup:
The web server acts as the intermediary,  receiving data from the aurduino and making it accesible to the user interface setting up the web server involves:
1. Web Server Software Installation: Install a web server software such as Node.js or Apache. These software packages provide the infrastructure for handling incoming data and serving webpages.
2. Web Server Script Creation: Create a web server script to handle incoming data from the Arduino. This script will listen for data on a specific port.
3. Socket Connection Establishment: Open a socket connection to listen for incoming data on the designated port. The socket acts as a virtual channel through which the web server receives data from the Arduino.

```javascript

const express = require("express");
const cors = require("cors");

const app = express();
// Allow requests from the frontend (adjust port if necessary)
app.use(
  cors({
    origin: "http://localhost:5500",
    methods: ["GET", "POST"],
    allowedHeaders: ["Content-Type", "Authorization"],
  })
);

const http = require("http");
const { SerialPort, ReadlineParser } = require("serialport");
const socketIo = require("socket.io");

const server = http.createServer(app);
const io = socketIo(server);

// Use the correct port path for your Arduino connection
const port = new SerialPort({
  path: "COM3", // Replace with your actual port
  baudRate: 9600,
});

const parser = port.pipe(new ReadlineParser({ delimiter: "\r\n" }));

// Serve the frontend HTML page
app.get("/", (req, res) => {
  res.sendFile(__dirname + "/instuction.html");
});
app.get("/question1", (req, res) => {
  res.sendFile(__dirname + "/question1.html");
});
app.get("/question2", (req, res) => {
  res.sendFile(__dirname + "/question2.html");
});
app.get("/question3", (req, res) => {
  res.sendFile(__dirname + "/question3.html");
});
app.get("/question4", (req, res) => {
  res.sendFile(__dirname + "/question4.html");
}); 
parser.on("data", (data) => {
  const trimmedData = data.trim();
  console.log("Received from Arduino:", trimmedData);

  const numericData = parseInt(trimmedData, 10); // Convert to number

  if (!isNaN(numericData)) {
    io.emit("data", numericData); // Emit numeric data
  }
 else if (trimmedData === "next") {
    io.emit("arduinoButtonNext"); // Emit event for Next
  } else if (trimmedData === "repeat") {
    io.emit("arduinoButtonRepeat"); // Emit event for Repeat
  }
});

port.on("error", (err) => {
  console.error("Serial Port Error:", err.message);
});

// Start the server
server.listen(5500, () => {
  console.log("Server is running on http://localhost:5500");
});

```
### Webpage Code
The webpage serves as the visual representation of the data received from the Arduino. It utilizes JavaScript to establish a connection with the web server, receive data, and update the user interface accordingly  This typically involves:

1.	JavaScript Library Inclusion:
    Include a JavaScript library for handling WebSocket communication. WebSocket provides a bi-directional communication channel between the webpage and     the web server.

2.	WebSocket Connection Establishment: Establish a WebSocket connection with the web server. This connection allows the webpage to receive real-time data updates from the Arduino.

3.	Data Reception: Listen for incoming data events using the WebSocket. On ('data') function. This function triggers whenever data is received from the web server.
4.	Data Parsing: Parse the received data into a meaningful format. The received data may be in a raw format and parsing it into a usable form is essential for the webpage.
5.	Webpage Update: Update the webpage elements based on the received data. This may involve manipulating text, images, or other interactive elements to reflect the sensor data or button states.

# Circuit Diagram

![image](https://github.com/user-attachments/assets/03e9b6ac-29a5-4af7-8971-45a28eb512c5)

The above circuit diagram represents the system that empowers visually impaired users to navigate webpages and select answers independently. This project utilizes an Arduino Uno as the brain, connected to a laptop and a specific webpage. Three buttons act as the user interface, allowing control over webpage navigation and answer selection.
The circuit revolves around the Arduino Uno and its connection points as shown. Each of the three buttons has one leg connected to a designated Arduino port: Port 2, Port 3, and Port 4 as shown. These ports essentially act as input channels for the Arduino. The other leg of each button connects to the Arduino's ground pin. This completes the circuit for each button, allowing them to send signals when pressed.
However, a small but crucial component sits alongside each button-to-ground connection: a capacitor. These tiny guardians play a vital role in "debouncing." When a button is pressed, it might register multiple presses due to electrical fluctuations. The capacitor acts like a temporary battery, absorbing and releasing this electrical bounce, ensuring a clean, single signal reaches the Arduino. Without debouncing, the system might misinterpret rapid presses.
The Arduino Uno connects to a laptop via an Arduino uno cable as shown. This connection establishes a vital communication channel called a serial port. Imagine it as a dedicated pathway for the Arduino to transmit data (button presses in this case) to the laptop.
These button when pressed translate into actions on the webpage. The laptop will run a script specifically designed for the chosen webpage. This script functions like a translator, constantly listening for incoming data (button presses) from the Arduino through the serial port connection.
The code written on both the Arduino and the webpage script translates button presses into specific actions:
Port 2 (Go to Next Page): Pressing the button connected to Port 2 signals the webpage script to navigate to the next page of the content.
Port 3 (Pick Answer): The number of times the button connected to Port 3 is pressed can be interpreted as the answer choice. The script then automatically selects that answer on a form or quiz.
Port 4 (Repeat Page): Pressing the button on Port 4 instructs the script to refresh the current webpage, allowing the user to review the content again.
This system offers significant value for visually impaired users. By translating button presses into clear actions, it empowers them to navigate webpages and participate in online activities independently. They gain control over their web experience, fostering greater autonomy and inclusivity.

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
