#include <iostream>
#include "blackjack.h"

int main(int argc, const char** argv){
    int return_code = blackjack::Game::Main(argc, argv);
    return return_code;
}