#include "game.h"
#include "score.h"
#include "title.h"

void main(void) {
    Title title;
    Game game;
    Score score;

    Title_enter(&title);
    for (; !title.startGame;) {
        Title_update(&title);
    }

    for (;;) {
        Game_enter(&game);
        for (; !game.allFinished;) {
            Game_update(&game);
        }

        Score_enter(&score, game.allSteps);
        for (; !score.startGame;) {
            Score_update(&score);
        }
    }
}
