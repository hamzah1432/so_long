# so_long

A simple 2D game project for 42 School where you need to collect all collectibles and reach the exit.

## Description
so_long is a project that requires creating a small 2D game using the MiniLibX graphics library. The player's goal is to collect all collectibles present on the map and reach the exit using the minimum possible moves.

## Requirements
- MiniLibX library
- Make
- GCC compiler

## Map Rules
- Maps must be `.ber` files
- Maps must be rectangular
- Maps must be surrounded by walls ('1')
- Maps must contain:
  - One exit ('E')
  - One player starting position ('P')
  - At least one collectible ('C')
- Maps must have a valid path

## Controls
- W or ↑ : Move up
- S or ↓ : Move down
- A or ← : Move left
- D or → : Move right
- ESC : Close game

## How to Run
```bash
make
./so_long maps/valid_map.ber
```

## Author
- halmuhis