#include <stdbool.h>

#ifndef TIC_TAC_TOE_IN_C_TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_IN_C_TIC_TAC_TOE_GAME_H

typedef struct GameData *Game;

enum Player {
	PLAYER_X = 100,
	PLAYER_O = 200
};

bool is_game_over(Game game);
Game new_game();
enum Player player_at_field(Game game, int x, int y);
void take_field(Game game, int x, int y);

#endif //TIC_TAC_TOE_IN_C_TIC_TAC_TOE_GAME_H
