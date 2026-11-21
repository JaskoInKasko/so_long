# so_long

## What the program does

so_long is a 2D game development project written in C using the MiniLibX graphics library. The objective is to create a simple graphical game in which the player navigates through a map, collects all collectibles, and reaches the exit.

The game reads a map from a `.ber` file and renders the environment using 2D textures. The player can move through the map while the program checks collisions, tracks collected items, and determines when the game has been completed.

The project includes:

- **2D graphics rendering:** Uses MiniLibX to display the game environment, including walls, floors, collectibles, the player, and the exit.
- **Map parsing:** Reads map layouts from `.ber` files and converts them into a playable game environment.
- **Map validation:** Checks map dimensions, boundaries, valid characters, and whether a valid path exists between the player, collectibles, and exit.
- **Player movement:** Handles keyboard input to move the player through the map.
- **Collision detection:** Prevents the player from moving through walls.
- **Collectible system:** Tracks the items collected by the player.
- **Game logic:** Allows the player to reach the exit only after collecting all required items.
- **Move counter:** Tracks and displays the number of moves made by the player.
- **Resource management:** Handles allocated memory, graphics resources, and window cleanup when the game is closed.

## How to execute the project

Navigate to the where the Makefile is:

```bash
cd Sourcecode
```

Compile the project using the Makefile:

```bash
make
```

Run the game with a valid `.ber` map file:

```bash
./so_long maps/map.ber
```

Replace `maps/map.ber` with the path to your desired map file.

Additional Makefile commands:

```bash
make clean
make fclean
make re
```

