
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
