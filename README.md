# 🌱 Conway's Game of Life
This project is an implementation of Conway's Game of Life, a cellular automaton devised by British mathematician John Conway in 1970. The simulation is written in C and supports initializing the first generation from a text file.

## 🎮 Game Description
Conway's Game of Life is a zero-player game where the evolution of a grid of cells is determined by its initial state, with no further input. The world is represented as a finite 2D grid, and each cell in the grid is either alive (1) or dead (0).

## ✅ Rules
Each cell’s state in the next generation depends on its 8 neighbors:

Underpopulation: A live cell with fewer than two live neighbors dies

Survival: A live cell with two or three live neighbors lives on

Overpopulation: A live cell with more than three live neighbors dies

Reproduction: A dead cell with exactly three live neighbors becomes a live cell

Note: Cells outside the grid are considered dead.

## 📂 File Structure
```bash
├── lifegame.c       # Core game logic (e.g., rules, next generation)
├── lifegame.h       # Header file for lifegame functions and constants
├── main.c           # Entry point and simulation loop
├── pattern.txt      # Example input file defining the initial state
└── README.md        # Project documentation
```

## 📄 Input Format
The file pattern.txt contains row-column coordinate pairs (0-based index) of initially alive cells. Each line represents one live cell:
```row col```

## 🔹 Example (pattern.txt):
```bash
1 2
1 3
1 4
2 1
2 2
2 3
```
This means:

The cell at row 1, column 2 is alive

The cell at row 1, column 3 is alive

etc.

All other cells in the grid are assumed dead initially.

## 🧪 How to Compile and Run
1. Compile the program:
```bash
gcc -o game main.c lifegame.c
```
2. Run the game (e.g., for 10 generations):
```bash
./game pattern.txt 10
```


