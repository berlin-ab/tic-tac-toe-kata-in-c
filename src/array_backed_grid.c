#include <stdlib.h>

#include "tic-tac-toe-game/grid.h"

struct GridData {
	GridItem plays[9];
};

static int position(int x, int y) {
	return x + (x*2) + y;
}

void insert_into_grid(Grid grid, int x, int y, GridItem item) {
	grid->plays[
		position(x, y)
	] = item;
}

GridItem value_in_grid(Grid grid, int x, int y) {
	return grid->plays[position(x, y)];
}

Grid make_grid() {
	return malloc(sizeof(Grid));
}
