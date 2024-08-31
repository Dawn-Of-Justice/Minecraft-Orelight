
# Minecraft Cube Light

Minecraft Cube Light is a project that replicates the ambiance of Minecraft's cube-based lighting system using NeoPixel LEDs controlled by an Arduino or compatible microcontroller.

<img src="https://github.com/Dawn-Of-Justice/Minecraft-Orelight/blob/master/images/cube-lightup.png" width="300" style="display: inline-block;"/>
<img src="https://github.com/Dawn-Of-Justice/Minecraft-Orelight/blob/master/images/cube.png" width="300" style="display: inline-block;"/>


## Features

-   **Dynamic Lighting**: Each face of the cube mimics the lighting mechanics of Minecraft blocks.
-   **Configurable Colors**: Customize colors and brightness levels easily.
-   **Interactive**: Responds to external triggers or commands (optional).
-   **Easy Integration**: Uses Adafruit NeoPixel library for seamless LED control.

## Hardware Requirements

-   Attiny85 
-   NeoPixel-compatible LEDs (number depending on cube size)
-   Jumper wires
-   Power supply for LEDs

## Software Requirements

-   Arduino IDE
-   Adafruit NeoPixel library

## Installation and Setup

1.  **Clone the Repository**
    
    `git clone https://github.com/yourusername/minecraft-cube-light.git` 
    
2.  **Install Dependencies**
    
    Install the Adafruit NeoPixel library in your Arduino IDE.
    
3.  **Connect Hardware**
    
    Connect NeoPixel LEDs according to your cube design and Arduino pin configuration.
    
4.  **Upload Code**
    
    Open `minecraft_cube_light.ino` in Arduino IDE, select your board and port, and upload the code to your Arduino.
    
5.  **Enjoy**
    
    Power up your Arduino and watch your Minecraft cube light up!
    

## Usage

-   Modify the `minecraft_cube_light.ino` file to customize colors, patterns, or behavior.
-   Experiment with different configurations of LEDs to create your desired lighting effects.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request with your enhancements.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
