#include "tic-tac-toe-game/tic_tac_toe_game.h"
#include "tic-tac-toe-game/grid.h"

#include <stdlib.h>

struct GameData {
	enum Player current_player;
	Grid grid;
};

struct Turn {
	Game game;
	int x;
	int y;
};

static void switch_players(Game game) {
	if (game->current_player == PLAYER_X) {
		game->current_player = PLAYER_O;
	} else {
		game->current_player = PLAYER_X;
	}
}

static void place_piece(struct Turn turn) {
	insert_into_grid(
		turn.game->grid,
		turn.x,
		turn.y,
		(void*)turn.game->current_player);
}

static bool field_taken(struct Turn turn) {
	return player_at_field(turn.game, turn.x, turn.y);
}

static void take_turn(struct Turn turn) {
	if (field_taken(turn))
		return;

	place_piece(turn);
	switch_players(turn.game);
}

/*
 * Public
 */
void take_field(Game game, int x, int y) {
	struct Turn turn;
	turn.x = x;
	turn.y = y;
	turn.game = game;
	
	take_turn(turn);
}

enum Player player_at_field(Game game, int x, int y) {
	return (enum Player) value_in_grid(game->grid, x, y);
}

Game new_game() {
	Game game = malloc(sizeof(Game));
	game->current_player = PLAYER_X;
	game->grid = make_grid();
	return game;
}

const int INVALID_PLAYER = 0; 

bool is_game_over(Game game) {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (player_at_field(game, i, j) == INVALID_PLAYER) {
				return false;
			}
		}
	}
	
	return true;
}
