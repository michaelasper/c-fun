#include <vector>
#include <deque>

namespace blackjack
{
    int randomNumber(int i);

    class Game
    {
        public:
            Game();
            static int Main(int argc, const char **argv);

        private:
            void Run();
            class Card{
                private:
                    int number;
                    std::string face;
                public:
                    Card();
                    Card(int number, std::string face): number(number), face(face) {}
                    void PrintCard();  

            };

            class Deck{
                private:
                    //TODO change std::vector to std::deque
                    std::deque < Card* > deckList;
                    std::string faceList[4] = {"♣️","♥️","♠️","♦️"};

                public:
                    Deck();
                    void Shuffle(int i);
                    void PrintDeck();
                    Card* Draw();
                
            };
            class Player{
                public:
                    Player();
                    void Action(Deck* deck);
                    void ShowHand();
                private:
                    std::vector< Card* > hand;
            };
    };
}