#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime> 

using namespace std;

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

void PrintStage(int wordLength){
    vector<string> stage = {"|----", "|   o", "|   T","|   ʌ"};
    for(auto &line: stage){
        cout << line << endl;
    }

    cout << endl;
    for(int i =0; i < wordLength; ++i){
        cout << "_ ";
    }
    cout << endl;
}

int main(){
    srand((unsigned)time(0)); 

    vector<string> words = LoadWords("words.txt");
    string word = words.at((rand()%words.size()));

    PrintStage(word.size());

    return 0;
}

