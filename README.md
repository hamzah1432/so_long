# so_long - 42 Project

A 2D game project where a player needs to collect all items and reach the exit while avoiding obstacles.

## About
This project is part of the 42 School curriculum. The goal is to create a basic 2D game using the MiniLibX graphics library where the player must collect all collectibles and reach the exit in the minimum number of moves.

## Game Rules
- Player must collect all collectibles before reaching the exit
- Movement counter is displayed in the shell
- Game closes when 'ESC' is pressed or when window's cross button is clicked
- Game ends when player reaches exit after collecting all items

## Technical Requirements
- MiniLibX library
- C compiler (gcc/clang)
- Make
- Linux/MacOS

## Map Configuration
- Files must have `.ber` extension
- Map must be composed of:
  - Walls ('1')
  - Empty space ('0')
  - Collectibles ('C')
  - Exit ('E')
  - Player starting position ('P')
- Map must be rectangular and closed by walls
- Must have exactly one exit, one starting position, and at least one collectible
- Must have a valid path to collect all items and reach the exit

## Controls
- W or Up Arrow : Move up
- S or Down Arrow : Move down
- A or Left Arrow : Move left
- D or Right Arrow : Move right
- ESC : Exit game

## Installation & Usage
```bash
# Clone the repository
git clone <repository-url>

# Navigate to project directory
cd so_long

# Compile the game
make

# Run the game with a map
./so_long maps/map.ber
```

## Error Management
- Program exits cleanly if no map is found
- Program displays "Error\n" followed by an explicit error message
- Maps are checked for validity before game starts

## Author
- halmuhis (42 login)

## License
This project is part of 42 School curriculum.