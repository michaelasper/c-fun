#include <iostream>
#include <string>
#include <algorithm>
#include <ctime> 
#include <cstdlib>
#include <vector>
#include <deque>

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

    void Game::Deck::Shuffle(int i)
    {
        for(int x = 0; x < i; ++x){
            std::random_shuffle(std::begin(deckList),std::end(deckList), randomNumber);
        }
    }

    void Game::Deck::PrintDeck()
    {
        for (auto &card: deckList)
        {
            card->PrintCard();
            std::cout << " ";
            
        }
        std::cout << std::endl;
    }

    Game::Card* Game::Deck::Draw(){
        Card *card = deckList[0];
        deckList.pop_front();
        return card;
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
        for(auto &card: hand){
            card->PrintCard();
            std::cout<<" ";
        }
        
        std::cout << std::endl;

    }

    void Game::Run()
    {
        Deck *deck = new Deck();
        deck->Shuffle(5);
        Player *player = new Player();
        player->Action(deck);
        player->Action(deck);
        player->Action(deck);
        player->Action(deck);
        player->Action(deck);
        player->ShowHand();
        deck->PrintDeck();
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