/*
 * lifegame.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "lifegame.h"

/* hard-coded world size */
#define WORLDWIDTH 39
#define WORLDHEIGHT 20

/* character representations of cell states */
#define CHAR_ALIVE '*'
#define CHAR_DEAD ' '

/* current cell states of the world */
static int world[WORLDWIDTH][WORLDHEIGHT];

/* next generation cell states */
static int nextstates[WORLDWIDTH][WORLDHEIGHT];

/* functions to write for Task 2 of lab */
void initialize_world_from_file(const char * filename) {
	/* TODO: read the state of the world from a file with
	   name "filename".  the live cells are given by pairs of rows and columns.
	 */
	 for (int i = 0; i < WORLDWIDTH; i++){
	     for (int j = 0; j < WORLDHEIGHT; j++) {
            world[i][j] = nextstates[i][j] = DEAD;
	     }
	 }

	 FILE *fp;
	 fp = fopen(filename, "r");

	 if(fp == NULL) {
        perror("Error opening the file");
        return;
	 }

	 int i, j;
	 while(fscanf(fp, "%d %d", &i, &j) != EOF) {
	     if(i >= 0 && i < WORLDWIDTH && j >= 0 && j < WORLDHEIGHT) {
	         world[i][j] = ALIVE;
         }
	 }

	 fclose(fp);
}

void save_world_to_file(const char * filename) {
	/* TODO: write the state of the world into a file with
	   name "filename".
	   only the live cells are saved in the file (in the form of rows and columns).

	   This file should be readable using the function
	   initialize_world_from_file(filename) above
	 */
	 FILE *fp;
	 fp = fopen(filename, "w");

	 if(fp == NULL) {
        perror("Error opening the file");
        return;
	 }

	 for (int i = 0; i < WORLDWIDTH; i++){
        for (int j = 0; j < WORLDHEIGHT; j++){
            if(world[i][j] == ALIVE){
                fprintf(fp, "%d %d\n", i, j);
            }
        }
	 }

	 fclose(fp);
}

/* you shouldn't need to edit anything below this line */

/* initializes the world to a hard-coded pattern, and resets
   all the cells in the next generation to DEAD */
void initialize_world(void) {
	int i, j;

	for (i = 0; i < WORLDWIDTH; i++)
		for (j = 0; j < WORLDHEIGHT; j++)
			world[i][j] = nextstates[i][j] = DEAD;
	/* pattern "glider" */
	world[1][2] = ALIVE;
	world[3][1] = ALIVE;
	world[3][2] = ALIVE;
	world[3][3] = ALIVE;
	world[2][3] = ALIVE;
}

int get_world_width(void) {
	return WORLDWIDTH;
}

int get_world_height(void) {
	return WORLDHEIGHT;
}

int get_cell_state(int x, int y) {
	if (x < 0 || x >= WORLDWIDTH || y < 0 || y >= WORLDHEIGHT)
		return DEAD;
	return world[x][y];
}

void set_cell_state(int x, int y, int state) {
	if (x < 0 || x >= WORLDWIDTH || y < 0 || y >= WORLDHEIGHT) {
		fprintf(stderr,"Error: coordinates (%d,%d) are invalid.\n", x, y);
		abort();
	}
	nextstates[x][y] = state;
}

void finalize_evolution(void) {
	int x, y;
	for (x = 0; x < WORLDWIDTH; x++) {
		for (y = 0; y < WORLDHEIGHT; y++) {
			world[x][y] = nextstates[x][y];
			nextstates[x][y] = DEAD;
		}
	}
}

void output_world(void) {
	char worldstr[2*WORLDWIDTH+2];
	int i, j;

	worldstr[2*WORLDWIDTH+1] = '\0';
	worldstr[0] = '+';
	for (i = 1; i < 2*WORLDWIDTH; i++)
		worldstr[i] = '-';
	worldstr[2*WORLDWIDTH] = '+';
	puts(worldstr);
	for (i = 0; i <= 2*WORLDWIDTH; i+=2)
		worldstr[i] = '|';
	for (i = 0; i < WORLDHEIGHT; i++) {
		for (j = 0; j < WORLDWIDTH; j++)
			worldstr[2*j+1] = world[j][i] == ALIVE ? CHAR_ALIVE : CHAR_DEAD;
		puts(worldstr);
	}
	worldstr[0] = '+';
	for (i = 1; i < 2*WORLDWIDTH; i++)
		worldstr[i] = '-';
	worldstr[2*WORLDWIDTH] = '+';
	puts(worldstr);
}
