var serial; // variable to hold an instance of the serialport library
var portName = 'COM3' //rename to the name of your port
var inData;
var dataarray = []; //some data coming in over serial!
var xPos = 0;

function setup() {
    serial = new p5.SerialPort();       // make a new instance of the serialport library
    serial.on('list', printList);       // set a callback function for the serialport list event
    serial.on('connected', serverConnected); // callback for connecting to the server
    serial.on('open', portOpen);        // callback for the port opening
    serial.on('data', serialEvent);     // callback for when new data arrives
    serial.on('error', serialError);    // callback for errors
    serial.on('close', portClose);      // callback for the port closing

    serial.list();                      // list the serial ports
    serial.open(portName);              // open a serial port
    createCanvas(1200, 800);
}

// get the list of ports:
function printList(portList) {
    // portList is an array of serial port names
    for (var i = 0; i < portList.length; i++) {
	// Display the list the console:
	print(i + " " + portList[i]);
    }
}

// prints info message to console
function serverConnected() {
    print('connected to server.');
}

// prints info message to console
function portOpen() {
    print('the serial port opened.')
}

// prints error message to console and appends error
function serialError(err) {
    print('Something went wrong with the serial port. ' + err);
}

// prints info message to console
function portClose() {
    print('The serial port closed.');
}

function serialEvent() {
  if (serial.available()) {
    var datastring = serial.readLine(); // readin some serial
    var newarray;
    try {
      newarray = JSON.parse(datastring); // can we parse the serial
      } catch(err) {
          //console.log(err);
    }
    if (typeof(newarray) == 'object') {
      dataarray = newarray;
    }
    console.log("got back " + datastring);
  }
}

//if Key pressed is the spacebar (ASCII code 32),
//then data is written back to Arduino
function keyPressed() {
  if (key == 32) {
    console.log("writing key");
    serial.write(key);
  }
}

function graphData(newData) {
  // map the range of the input to the window height:
  var yPos = map(newData, 0, 1023, 0, height);
  // draw the line
  line(xPos, height, xPos, height - yPos);
  // at the edge of the screen, go back to the beginning:
  if (xPos >= width) {
    xPos = 0;
    // clear the screen by resetting the background:
    background(0x08, 0x16, 0x40);
  } else {
    // pass
  }
}

function draw() {
  stroke('rgba(0,255,0,0.25)'); // green
  graphData(dataarray[0]);

  stroke('rgba(0,80,255,0.5)'); // blue
  graphData(dataarray[1]);
  xPos++;
}