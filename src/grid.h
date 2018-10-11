#ifndef TIC_TAC_TOE_IN_C_GRID_H
#define TIC_TAC_TOE_IN_C_GRID_H

typedef struct GridData *Grid;
typedef void *GridItem;

extern Grid make_grid();
extern void insert_into_grid(Grid grid, int x, int y, GridItem item);
extern GridItem value_in_grid(Grid grid, int x, int y);

#endif //TIC_TAC_TOE_IN_C_GRID_H
