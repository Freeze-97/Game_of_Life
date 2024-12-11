# Game of Life
The Game of Life was invented by John Conway in 1970. The game consists of a two-dimensional world
extending infinitely in all directions, divided into “cells.” Each cell is either “dead” or
“alive” at a given “generation.” The game consists of a set of rules that describe how the
cells evolve from generation to generation.

These rules calculate the state of a cell in the next generation as a function of the states
of its neighboring cells in the current generation. In a two-dimensional world, a cell’s
neighbors are those 8 cells vertically, horizontally, or diagonally adjacent to that cell.
Conway’s set of rules are summarized as follows:
1. Any live cell with fewer than two live neighbors dies, as if caused by underpopulation.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by overcrowding.
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by
reproduction.

In this version the two-dimensional world is finite. The neighbors of a cell on the edge
(borders) that are beyond the edge are assumed dead.
