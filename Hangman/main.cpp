#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime> 
#include <set>

using namespace std;

/**
    Loads up words from a text file

    @param filename of word list
    @return a vector of strings
*/
vector<string> LoadWords(string filename){
    ifstream reader(filename);
    string line;
    vector<string> words;
    for(int i = 0; ! reader.eof(); i++){
        getline(reader, line);
        words.push_back(line);
    }

    reader.close();
    return words;
}

int Hangman(string word, set<char> previousGuesses){
    vector<string> stage = {"|----", "|   o", "|   T","|   ʌ"};
    string correct = "";
    int wrong = 0;
    bool allCorrect = true;
    
    for(auto &letter: previousGuesses){
        if(word.find(letter) == string::npos){
            ++wrong;
        }
    }

    for(int i = 0; i < stage.size(); ++i){
        if(i <= wrong ){
            cout << stage.at(i) << endl;
        }else{
            cout << "|" << endl;
        }
    }
    
    cout << endl;
    for(auto &letter: word){
        if(previousGuesses.count(letter)){
            cout << letter << " ";
        }else{
            cout << "_ ";
            allCorrect = false;
        }
    }
    cout << endl << endl;

    if(allCorrect){
        cout << "YOU WIN" << endl;
        exit(0);
    }
    return wrong;
}

bool MakeGuess(char guess, string word, set<char> previousGuesses){
    return (3 != Hangman(word, previousGuesses));
}


int main(){
    srand((unsigned)time(0)); 
    bool gameRunning = true;
    set<char> previousGuesses;
     
    /// Initializing word list
    vector<string> words = LoadWords("words.txt");
    string word = words.at((rand()%words.size()));

    cout << word << endl;
    /// Print the initial stage
    Hangman(word, previousGuesses);

    while(gameRunning){
        char guess;
        cin >> guess;
        cout << endl << endl;
        previousGuesses.insert(guess);
        gameRunning = MakeGuess(guess, word, previousGuesses);
    }

    cout << "YOU LOSE" << endl;

    return 0;
}

