# Arduino-project-automatic-pill-dispenser
Here's a repo linked to a project I got to do in school : creating an automatic pill dispenser with an Arduino card. 

## What will be the main components ? 

<br> Our main components will be our App and a microcontroller.
The App will be taking orders from the user while the microcontroller will receive and execute them.

### Our App

<br>The User Interface is an Android app created with MIT's tool for app creation.
<br>Here's the link to the website : https://appinventor.mit.edu (or you can click the image).

<a href="https://appinventor.mit.edu"><img width="1440" alt="Capture d’écran 2024-01-05 à 21 43 48" src="https://github.com/thatgirlAm/Arduino-project-automatic-pill-dispenser/assets/117035426/944cea22-fe22-448a-bf61-1e4c73783e15" ></a>
<br>The .aia document is in the repo, you could just download it as well as the arduino file and they are fully functionnal. <br>
<br>Here's a picture of our App, it was a very simple one: 

<br>Through it we can : 
<br>- open and close a drawer thanks to servo motors
<br>- program an alarm (not an alarm from the device, it is a buzzer intergrated in our circuit that goes off)
<br>- check the history of the patient's consumption

### Electronics...

<br>The Arduino board communicates with the tablet through a bluetooth module. 
<br>The bluetooth module has 4 pins : VCC+ (3,7 to 5V), the GRND, the TX (transmitor) and the RX (the receptor).
<br><b>Warning : The transmittor of the arduino is connected to the receptor of the module and its receptor to the transmittor of the bluetooth module.</b>
<br>All the information regarding cabling etc. is findable o, the internet, it is very simple, a few LEDs, a buzzer, a digicode aznd servos.


