#include <iostream>
#include <string>
#include <algorithm>
#include <ctime> 
#include <cstdlib>
#include <vector>

#include "blackjack.h"

namespace blackjack
{
   int randomNumber(int i){
       std::srand ( unsigned ( std::time(0) ) );
       return std::rand() % i;
   }

    void Game::Card::PrintCard(){
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
                //deckList[(i * 13) + j] = new Deck::Card(j + 1, faceList[i]);
                 deckList.push_back(new Card(j + 1, faceList[i]));
            }
        }
    }

    void Game::Deck::Shuffle()
    {
        
        std::random_shuffle(std::begin(deckList),std::end(deckList), randomNumber);
    }

    void Game::Deck::PrintDeck()
    {
        for (int i = 0; i < 52; ++i)
        {
            if(i % 13 == 0 && i > 0) std::cout << std::endl;
            deckList[i]->PrintCard();
            std::cout << " ";
            
        }
        std::cout << std::endl;
    }

    Game::Card* Game::Deck::Draw(){
        return deckList[0];
    }

    Game::Game()
    {
    }

    Game::Player::Player(){

    }

    void Game::Player::Action(Deck* deck){
        hand.push_back(deck->Draw());

    }

    void Game::Player::ShowHand(){
        hand[0]->PrintCard();
        std::cout << std::endl;

    }

    void Game::Run()
    {
        Deck *deck = new Deck();
        deck->Shuffle();
        Player *player = new Player();
        player->Action(deck);
        player->ShowHand();
    }

    int Game::Main(int argc, const char **argv)
    {
        Game *game = new Game();
        game->Run();
        return 0;
    }
}