#include "pch.h"
#include "Game.h"
#include "Prepare.h"

int main()
{       
    std::srand(unsigned int(std::time(NULL)));

    if (prepareFunction() == true) {
        Game game;
        while (game.running())
        {
            game.update();
            game.render();
        }
    }
    else {
        std::cerr << "Game could not start!" << std::endl;
    }
    return 0;
}