#include <cgreen/cgreen.h>

#include "tic-tac-toe-game/grid.h"

Describe(Grid);
BeforeEach(Grid) {}
AfterEach(Grid) {}

Ensure(Grid, items_can_be_placed_into_the_grid) {
	Grid grid = make_grid();
	insert_into_grid(grid, 0, 0, (GridItem) 1);
	
	assert_that(value_in_grid(grid, 0, 0), 
		is_equal_to((GridItem) 1));
}

Ensure(Grid, items_can_be_replaced_in_the_grid) {
	Grid grid = make_grid();
	insert_into_grid(grid, 0, 0, (GridItem) 1);
	insert_into_grid(grid, 0, 0, (GridItem) 2);
	
	assert_that(value_in_grid(grid, 0, 0), 
		is_equal_to((GridItem) 2));
}

Ensure(Grid, empty_slots_in_the_grid_return_invalid_code) {
	Grid grid = make_grid();
	
	assert_that(value_in_grid(grid, 0, 0), 
		is_equal_to((GridItem) INVALID_GRID_ITEM));
}

Ensure(Grid, out_of_bounds_requests_from_the_grid_returns_an_invalid_code) {
	Grid grid = make_grid();

	assert_that(value_in_grid(grid, 0, -1),
	            is_equal_to((GridItem) INVALID_GRID_ITEM));

	assert_that(value_in_grid(grid, -1, 0),
	            is_equal_to((GridItem) INVALID_GRID_ITEM));

	assert_that(value_in_grid(grid, 3, 0),
	            is_equal_to((GridItem) INVALID_GRID_ITEM));

	assert_that(value_in_grid(grid, 0, 3),
	            is_equal_to((GridItem) INVALID_GRID_ITEM));
}

enum VALUES {
	ONE, 
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE
};

Ensure(Grid, each_position_can_hold_a_value) {
	Grid grid = make_grid();
	
	insert_into_grid(grid, 0, 0, (GridItem) ONE);
	insert_into_grid(grid, 0, 1, (GridItem) TWO);
	insert_into_grid(grid, 0, 2, (GridItem) THREE);
	insert_into_grid(grid, 1, 0, (GridItem) FOUR);
	insert_into_grid(grid, 1, 1, (GridItem) FIVE);
	insert_into_grid(grid, 1, 2, (GridItem) SIX);
	insert_into_grid(grid, 2, 0, (GridItem) SEVEN);
	insert_into_grid(grid, 2, 1, (GridItem) EIGHT);
	insert_into_grid(grid, 2, 2, (GridItem) NINE);

	assert_that(value_in_grid(grid, 0, 0), is_equal_to(ONE));
	assert_that(value_in_grid(grid, 0, 1), is_equal_to(TWO));
	assert_that(value_in_grid(grid, 0, 2), is_equal_to(THREE));
	assert_that(value_in_grid(grid, 1, 0), is_equal_to(FOUR));
	assert_that(value_in_grid(grid, 1, 1), is_equal_to(FIVE));
	assert_that(value_in_grid(grid, 1, 2), is_equal_to(SIX));
	assert_that(value_in_grid(grid, 2, 0), is_equal_to(SEVEN));
	assert_that(value_in_grid(grid, 2, 1), is_equal_to(EIGHT));
	assert_that(value_in_grid(grid, 2, 2), is_equal_to(NINE));
}

static int test_position(int x, int y) {
	return x + (x*2) + y;
}


Ensure(Grid, position) {
	assert_that(test_position(0, 0), 
		is_equal_to(0));
	assert_that(test_position(1, 0), 
		is_equal_to(3));
	assert_that(test_position(1, 1), 
			is_equal_to(4));
	assert_that(test_position(2, 0), 
			is_equal_to(6));
	assert_that(test_position(2, 1), 
			is_equal_to(7));
	assert_that(test_position(2, 2), 
			is_equal_to(8));
}


int main() {
	TestSuite *suite = create_test_suite();
	add_test_with_context(suite, Grid, items_can_be_placed_into_the_grid);
	add_test_with_context(suite, Grid, items_can_be_replaced_in_the_grid);
	add_test_with_context(suite, Grid, empty_slots_in_the_grid_return_invalid_code);
	add_test_with_context(suite, Grid, out_of_bounds_requests_from_the_grid_returns_an_invalid_code);
	add_test_with_context(suite, Grid, each_position_can_hold_a_value);
	add_test_with_context(suite, Grid, position);
	return run_test_suite(suite, create_text_reporter());
}
