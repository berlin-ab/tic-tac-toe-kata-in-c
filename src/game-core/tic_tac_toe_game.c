#include "tic-tac-toe-game/tic_tac_toe_game.h"
#include "tic-tac-toe-game/grid.h"

#include <stdlib.h>

static const int INVALID_PLAYER = 0;
static const int GRID_WIDTH = 3;

struct GameData {
	enum Player current_player;
	Grid grid;
};

static void switch_players(Game game) {
	if (game->current_player == PLAYER_X) {
		game->current_player = PLAYER_O;
		return;
	}
	
	game->current_player = PLAYER_X;
}

struct Turn {
	Game game;
	int x;
	int y;
};

static void place_piece(struct Turn turn) {
	insert_into_grid(
		turn.game->grid, 
		turn.x, 
		turn.y, 
		(GridItem) turn.game->current_player);
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

struct Turn build_turn(Game game, int x, int y) {
	struct Turn turn;
	turn.x = x;
	turn.y = y;
	turn.game = game;
	return turn;
}

/*
 * 
 * Public
 * 
 */
void take_field(Game game, int x, int y) {
	take_turn(
		build_turn(game, x, y)
		);
}

enum Player player_at_field(Game game, int x, int y) {

	GridItem gridItem = value_in_grid(
		game->grid, x, y);

	if (gridItem == INVALID_GRID_ITEM) {
		return (enum Player) INVALID_PLAYER;
	} else {
		return (enum Player) gridItem;
	}
}

Game new_game() {
	Game game = malloc(sizeof(Game));
	game->current_player = PLAYER_X;
	game->grid = make_grid();
	return game;
}

bool is_game_over(Game game) {
	for (int x = 0; x < GRID_WIDTH; x++)
		for (int y = 0; y < GRID_WIDTH; y++)
			if (player_at_field(game, x, y) == INVALID_PLAYER)
				return false;
	
	return true;
}
