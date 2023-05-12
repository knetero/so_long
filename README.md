# so_long

The purpose of this project is to build a small 2D video game using MiniLibX and learn a bit about how a simple video game usually works. I made my graphics to match the style of Jujitsu Kaisen anime, were you play as Gojo, the powerful sorcerer from the Jujitsu Kaisen anime. Your goal is to collect demons and assemble the powerful cursed object known as the finger.


# How to play ?

You need to compile all source files with make all.

To launch the game, execute `./so_long` with a map as argument: `./so_long maps/map.ber`

Pay attention: minimize is not working!

Maps
The game is able to play any map you want as long as it follow some specific rules:

The map has to be a .ber file.
It can only contain some of the following characters:


| Character |	         Object            |
| --------- | -------------------------- |
|   `1`	    |  Wall.                     |
|   `0`	    |  Empty space.              |
|   `C`	    |  Collectable.              |
|   `E`	    |  Exit.                     |
|   `P`	    |  Player starting position. |


The map must be a rectangle surrounded by walls `1`.
It must have at least one exit `E` and one collectable `C`. And only one player `P`.


<img width="1498" alt="Screen Shot 2023-05-12 at 1 08 57 PM" src="https://github.com/knetero/so_long/assets/100490192/019e12b6-09f6-4bc8-a173-877de30445e4">
