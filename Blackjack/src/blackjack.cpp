#include <iostream>
#include "blackjack.h"

namespace blackjack{
    
    Game::Game(){

    }

    void Game::Run(){
        std::cout << "Hello World" << std::endl;
    }

    int Game::Main(int argc, const char** argv){
        Game* game = new Game();
        game->Run();
        return 0;
    }
}