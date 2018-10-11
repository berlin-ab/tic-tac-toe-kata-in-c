#include "tic-tac-toe-game/tic_tac_toe_game.h"
#include <stdlib.h>

struct GameData {
	enum Player current_player;
	enum Player plays[9];
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

static int position(int x, int y) {
	return x + (x*2) + y;
}

static void place_piece(struct Turn turn) {
	turn.game->plays[
		position(turn.x, turn.y)
		] = turn.game->current_player;
}

static bool field_taken(struct Turn turn) {
	return turn.game->plays[position(turn.x, turn.y)];
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
	return game->plays[position(x, y)];
}

Game new_game() {
	Game game = malloc(sizeof(Game));
	game->current_player = PLAYER_X;
	return game;
}

bool is_game_over(Game game) {
	for (int i = 0; i < 9; ++i)
	{
		if (game->plays[i] == 0) {
			return false;
		}
	}

	return true;
}
