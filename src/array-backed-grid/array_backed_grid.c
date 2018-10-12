#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "tic-tac-toe-game/grid.h"

const GridItem INVALID_GRID_ITEM = (GridItem) -1;
static const int GRID_SIZE = 9;

struct GridData {
	GridItem plays[GRID_SIZE];
};

static int position(int x, int y) {
	return x + (x*2) + y;
}

static bool outside_of_bounds(int value) {
	return value > 2 || value < 0;
}

static void fill_grid(Grid grid) {
	for(int i = 0; i < GRID_SIZE; i++)
		grid->plays[i] = INVALID_GRID_ITEM;
}

/*
 * 
 * Public:
 * 
 */
void insert_into_grid(Grid grid, int x, int y, GridItem item) {
	int p = position(x, y);
	
	printf("Inserting into position: %d value %d\n", p, item);
	
	grid->plays[p] = item;
}

GridItem value_in_grid(Grid grid, int x, int y) {
	if (outside_of_bounds(x) || outside_of_bounds(y)) {
		return INVALID_GRID_ITEM;
	}
	
	int p = position(x, y);
	GridItem found = grid->plays[p];
	
	printf("found position: %d value\n", p, (int)found);
	return found;
}

Grid make_grid() {
	Grid grid = malloc(sizeof(Grid));
	fill_grid(grid);
	return grid;
}
