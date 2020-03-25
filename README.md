# arduino_space_shooter
Interesting game written for use with an Arduino and a 20x4 LCD<br>
This game was inspired by the Nokia Space Impact game, but is less complex because of limitations in how sprites are handled by the LCD controller<br>
## My experience
### Why did I make this?
I made it to experiment using LCD screens with Arduino. Also, I wanted to try using a 3.3v Pro Mini with a 5v power source and/ or a 3.7v Li-Po battery by removing the DC-DC converter present on the board.<br>
The whole framework can be reused for even more interesting projects. One thing that comes to my mind is modifying this project into a system resource monitor for PCs (connected via serial or via bluetooth).
### What did I learn?
From a programming standpoint, I learned a lot: how to use an LCD, how to use custom characters, how to time all the events to make a playable game, how to randomly generate levels, how to keep a high-score in memory.<br>
From a User Interface designer standpoint, I learned how to: make a playable game; design menus with limited resources; design a game that rewards the user by giving points, managing health points and using collectable 'coins'.<br>
Of course, My electrical engineering skills got better too, because I learned to use a capacitor debouncer for the buttons, I used pull-down resistors and I improved my soldering skills.<br>
I plan to design and 3d print a case, which will be another great learning experience.
## How to make it
### Components list
1. Arduino (I used a 8MHz Arduino Pro Mini clone, any AVR board should be fine)
2. 3× push buttons
3. 3× 10kΩ resistor
4. 3× 100kΩ resistor
5. 3× 100nF capacitor
6. 1× 10kΩ potentiometer<br>
The component values don't have to be exact, a little variation is Ok.<br>
### Circuit diagram
![Circuit diagram](https://github.com/vhateg/arduino_space_shooter/blob/master/schematic.png) <br>
Note: pay close attention to the resistors and their position.<br>Also, the project was made a while ago, so there is a very small chance that the diagram may contain errors (but I doubt it because I had the physical circuit on my desk when drawing it)
