[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badges/) [![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://mit-licence.igorabrandao.com.br/)

# Flood-It project
Repository containing the Flood-it project meant to test the [custom made data-structures](https://github.com/igorabrandao/Data-structures).


## Overview

<p align="center">
  <img style="width:150px;" src="https://igorabrandao.com.br/igorabrandao/flood_it/Flood_It.png" alt="Flood-It game"/>
</p>

“Flood it” is a turn-based puzzle game whose objective is to “flood” an area. defined by a 14x14 matrix in a maximum of 25 turns. The "flood" occurs by filling the matrix cells with a single color. For this, the player must choose, at each turn, a color to be "placed" in the upper left corner. This color will replace (fill) the from the cell in the upper left corner, the entire adjacent area formed by cells that have the same color. If the player can fill the entire matrix in up to 25 moves, he wins, otherwise loses.

## Licence

Project under [MIT Licence](https://mit-licence.igorabrandao.com.br/).

## How ​​to compile

Use the makefile by typing the **'make'** command from the terminal, after navigating to the project folder.

## Project structure

We seek to use a more sophisticated structure for the game as a whole, performing the platform management in classes responsible for managing different elements of the game, separated as follows:

**FloodIt.h** => Manages the game main definitions.

**GameInterface.h** => Handles user interactions with the ga,e.

**File.h** => Repsonsible for generating the config file.

**config.h** => Holds the game settings.

**color.hpp** => Holds the tiles color definition

**Matrix.h** => Custom made data structure used to develop the game. It can be found in [this repository](https://github.com/igorabrandao/Data-structures)

## Ways to contribute

You can help us to make this projet even better :rocket:. Here are the ways you can contribute to this project:

### 1. Giving a feedback

Report your feedback, issues or suggestions by [creating a topic here](https://github.com/igorabrandao/Flood_IT/issues) :punch:.

### 2. Developing with us

Bring your dev skills to the team :computer:.

### 3. Making a donation

As you know, this project will remain free forever. If you like our work and find it useful, please help science initiatives spread out. Your contribution will be greatly appreciated and help me continue to develop this awesome projects crafted with :heart:

[![paypal](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=7NV5RV8B2MTA4)

## Contributors:

### Developing

* Igor Brandão
