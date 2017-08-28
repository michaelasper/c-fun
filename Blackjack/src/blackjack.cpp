#include <iostream>
#include <string>
#include "blackjack.h"

namespace blackjack
{
   
    


    void Game::Deck::Card::PrintCard(){
        if(number > 10 || number == 1){
            switch(number){
                case 1:
                    std::cout << "A" << face;
                    break;
                case 11:
                    std::cout << "J" << face;
                    break;
                case 12:
                    std::cout << "Q" << face;
                    break;
                case 13:
                    std::cout << "K" << face;
                    break;
                default:
                    break; 

            }
        }else{
            std::cout << number << face;
        }
    }


    Game::Deck::Deck()
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 13; ++j)
            {
                deckList[(i * 13) + j] = new Deck::Card(j + 1, faceList[i]);
            }
        }
    }

    void Game::Deck::Shuffle()
    {
    }

    void Game::Deck::PrintDeck()
    {
        for (int i = 0; i < 52; ++i)
        {
            deckList[i]->PrintCard();
            std::cout << std::endl;
        }
    }

    Game::Game()
    {
    }

    void Game::Run()
    {
        Deck *deck = new Deck();
        deck->PrintDeck();
    }

    int Game::Main(int argc, const char **argv)
    {
        Game *game = new Game();
        game->Run();
        return 0;
    }
}