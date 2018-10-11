#include <cgreen/cgreen.h>
#include "tic-tac-toe-game/tic_tac_toe_game.h"

// a game is over when all fields are taken
// a game is over when all fields in a column are taken by a player
// a game is over when all fields in a row are taken by a player
// a game is over when all fields in a diagonal are taken by a player
// a player can take a field if not already taken
// players take turns taking fields until the game is over
// there are two player in the game (X and O)

Describe(TicTacToeGame);
BeforeEach(TicTacToeGame) {}
AfterEach(TicTacToeGame) {}

Ensure(TicTacToeGame, new_game_is_not_over) {
	assert_that(
		is_game_over(new_game()), 
		is_equal_to(false)
		);
}

Ensure(TicTacToeGame, a_field_can_be_taken_by_x) {
	Game game = new_game();
	
	take_field(game, 0, 0);
	
	enum Player player = player_at_field(game, 0, 0);
	
	assert_that(player, 
		is_equal_to(PLAYER_X));
}

Ensure(TicTacToeGame, a_field_can_be_taken_by_o) {
	Game game = new_game();
	
	take_field(game, 0, 0);
	take_field(game, 0, 1);
	
	enum Player player = player_at_field(game, 0, 1);
	
	assert_that(player, 
		is_equal_to(PLAYER_O));
}

Ensure(TicTacToeGame, a_field_cannot_be_taken_twice) {
	Game game = new_game();
	
	take_field(game, 0, 0);
	take_field(game, 0, 0);

	enum Player player = player_at_field(game, 0, 0);

	assert_that(player,
		is_equal_to(PLAYER_X));	
}


//Ensure(TicTacToeGame, position) {
//	assert_that(test_position(1, 0),
//		is_equal_to(3));
//	assert_that(test_position(1, 1), 
//			is_equal_to(4));
//	assert_that(test_position(2, 0), 
//			is_equal_to(6));
//	assert_that(test_position(2, 1), 
//			is_equal_to(7));
//}

Ensure(TicTacToeGame, a_game_is_over_when_all_fields_are_taken) {
	Game game = new_game();
	
	// x,o,x
	// x,o,o
	// o,x,x
	
	take_field(game, 0, 0); // x
	take_field(game, 0, 1); // o
	take_field(game, 0, 2); // x
	take_field(game, 1, 1); // o
	take_field(game, 1, 0); // x
	take_field(game, 1, 2); // o
	take_field(game, 2, 1); // x
	take_field(game, 2, 0); // o
	take_field(game, 2, 2); // x

	assert_that(is_game_over(game),
		is_equal_to(true));
}

int main() {
	TestSuite *suite = create_test_suite();
	add_test_with_context(suite, TicTacToeGame, new_game_is_not_over);
	add_test_with_context(suite, TicTacToeGame, a_field_can_be_taken_by_x);
	add_test_with_context(suite, TicTacToeGame, a_field_can_be_taken_by_o);
	add_test_with_context(suite, TicTacToeGame, a_field_cannot_be_taken_twice);
	add_test_with_context(suite, TicTacToeGame, a_game_is_over_when_all_fields_are_taken);
	
	return run_test_suite(suite, create_text_reporter());
}
