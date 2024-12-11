/*
 * lab4-task2.c  (implementation of lab4 task 1-3)
 *
 *  Created on: 2024-12-09
 *      Author: Tommy
 */

#include <stdio.h>

/* include helper functions for game */
#include "lifegame.h"

/* add whatever other includes here */

/* number of generations to evolve the world */
#define NUM_GENERATIONS 50

/* this function should set the state of all
   the cells in the next generation and call
   finalize_evolution() to update the current
   state of the world to the next generation */
void next_generation(void);

/* this function should return the state of the cell
   at (x,y) in the next generation, according to the
   rules of Conway's Game of Life (see handout) */
int get_next_state(int x, int y);

/* this function should calculate the number of alive
   neighbors of the cell at (x,y) */
int num_neighbors(int x, int y);

int main(int argc, char ** argv)
{
	int n;

	/* TODO:
        read in a file name (for live cells)
        initialize the world, from this file if it is readable
           otherwise, use hard-coded pattern by calling initialize_world( )   */
    if(argc > 1) {
        printf("Initializing world from file.\n");

        // See if file exist
        FILE *fp = fopen(argv[1], "r");
        if(fp) {
            fclose(fp);
            initialize_world_from_file(argv[1]);
        } else {
            perror("Error opening the file");
            printf("Initializing world hard-coded.\n");
            initialize_world();
        }
    } else {
        printf("Initializing world hard-coded.\n");
        initialize_world();
    }

	/* evolutions*/
	for (n = 0; n < NUM_GENERATIONS; n++) {
		next_generation();   /* you implemented in lab4 task 1-2*/

		/* TODO: output the world state to console ==> you complete it in lab4 task 1-2 */
		output_world();

		/* TODO: let the program pause, until you press ENTER key to continue ==> you did it in lab4 task 1-2*/
		printf("Press ENTER to continue...\n");
		getchar();
	}

	/* TODO: output the world state to file world.txt ==> you need complete it*/
	char *filename = "world.txt";
	save_world_to_file(filename);

	return 0;
}

/* the following functions are implemented in lab4 task 1-2, and you can copy from that file*/
void next_generation(void) {
	/* TODO: for every cell, set the state in the next
	   generation according to the Game of Life rules

	   Hint: use get_next_state(x,y) */

    for (int x = 0; x < get_world_width(); x++) {
        for (int y = 0; y < get_world_height(); y++) {
            set_cell_state(x, y, get_next_state(x,y));
		}
	}

	finalize_evolution(); /* called at end to finalize */
}

int get_next_state(int x, int y) {
	/* TODO: for the specified cell, compute the state in
	   the next generation using the rules

	   Use num_neighbors(x,y) to compute the number of live
	   neighbors */

    int neighbors_alive = num_neighbors(x, y);
    int cell_state = get_cell_state(x, y);

    if (cell_state == ALIVE) {
        if (neighbors_alive < 2 || neighbors_alive > 3) { // Over or under population
            return DEAD;
        } else {
            return ALIVE;
        }
    } else { // cell_state == DEAD
        if (neighbors_alive == 3) {// Becomes alive because of reproduction
            return ALIVE;
        } else {
            return DEAD;
        }
    }
}

int num_neighbors(int x, int y) {
	/* TODO: for the specified cell, return the number of
	   neighbors that are ALIVE

	   Use get_cell_state(x,y) */

    int num_alive = 0;
    for(int i = x - 1; i <= x + 1; i++) {
        for(int j = y - 1; j <= y + 1; j++) {
            if(!(i == x && j == y)) { // Do not check the same specified cell x, y
                num_alive += get_cell_state(i, j);
            }
        }
    }

    return num_alive;
}
