# Magic Mouse (An Aurdinio device that is used to assist blind persons in taking examinations on a website)
MagicMouse is a Node.js project that enables real-time communication between a server and clients using WebSockets. It also integrates serial port communication, making it useful for hardware-related applications.

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

# License
This project is licensed under the ISC license.

## Contribution
Feel free to fork and contribute to this project by creating pull requests.

