#include "game.h"

int main(){
    Game* game = new Game(5, 6);
    game->simulate();

    delete game;
    return 0;
}