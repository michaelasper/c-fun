namespace blackjack
{
    class Game
    {
        public:
            Game();
            static int Main(int argc, const char **argv);

        private:
            void Run();
            class Deck{
                public:
                    Deck();
                    void Shuffle();
                    void PrintDeck();

                private:
                    class Card{
                        private:
                            int number;
                            std::string face;
                        public:
                            Card();
                            Card(int number, std::string face): number(number), face(face) {}
                            void PrintCard();
                            
                    };
                    Card* deckList[52];
                    std::string faceList[4] = {"♣️","❤","♠️","♦️"};
            };
    };
}