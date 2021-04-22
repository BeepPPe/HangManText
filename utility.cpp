#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include "utility.h"
#include "draw.h"
using namespace std;

char readAGuess()
{
    char guess;
    cout << "Please enter your next guess: ";
    cin >> guess;
    return guess;
}


string normalize(const string& s)
{
    string news = s;
    transform(s.begin(), s.end(), news.begin(), ::tolower);
    return news;
}

string chooseWord(const string& fileName, const int& index)
{
    vector<string> vocabulary;
    ifstream file(fileName);
    if (!file.is_open())
        return "";

    while (!file.eof()) {
        string line;
        getline(file, line);
        if (file && !line.empty())
            vocabulary.push_back(normalize(line));
    }

    int n = vocabulary.size();
    cout << "vocabulary size = " << n << endl;
    return n > 0 ? vocabulary[index] : "";
}

bool contains(string word, char guess)
{
    return (word.find(guess) != string::npos);
}

void update(string& guessedWord, const string& word, char guess)
{
    int n = guessedWord.length();
    for (int i = 0; i < n; i++) {
        if (word[i] == guess)
            guessedWord[i] = guess;
    }
}

string ChooseTopic()
{
    clearScreen();
    cout << "Select Your Topics" << endl;
    cout << "1.Animal    2.Food and drinks\n";
    cout << "Your choice: ";
    int choice1;
    cin >> choice1;
    if (choice1 == 1)
    {
        clearScreen();
        cout <<"Choose Difficulty\n";
        cout <<"1.Easy    2.Hard\n";
        cout << "Your choice: ";
        int choice2;
        cin >> choice2;
        if (choice2 == 1)
            return "WordList/Animal/EASY.txt";
        else if (choice2 == 2)
            return "WordList/Animal/HARD.txt";
        else
        {
            cout <<"\n Invalid Input! Try Again";
            _getch();
            ChooseTopic();
        }
    }
    else if (choice1 == 2)
    {
        clearScreen();
        cout <<"Choose Difficulty\n";
        cout <<"1.Easy    2.Hard\n";
        cout << "Your choice: ";
        int choice2;
        cin >> choice2;
        if (choice2 == 1)
            return "WordList/FoodAndDrink/EASY.txt";
        else if (choice2 == 2)
            return "WordList/FoodAndDrink/HARD.txt";
        else
        {
            cout <<"\n Invalid Input! Try Again";
            _getch();
            ChooseTopic();
        }
    }
    else
    {
        cout <<"\n Invalid Input! Try Again";
            _getch();
            ChooseTopic();
    }

}

int ChooseIndex(const string& fileName)
{
    vector<string> vocabulary;
    ifstream file(fileName);
    if (!file.is_open())
        return -1;

    while (!file.eof()) {
        string line;
        getline(file, line);
        if (file && !line.empty())
            vocabulary.push_back(normalize(line));
    }
    int n = vocabulary.size();
    return rand() % n;
}

//Main game
void Game()
{
    string fileName = ChooseTopic();
    string fileHint = FileHint(fileName);
    while (true) {
        int index = ChooseIndex(fileName);
        string word = chooseWord(fileName, index);
        string hint = chooseWord(fileHint, index);
        if (word.empty()) {
            cout << "No word available in " << fileName << endl;
            return;
        }
        string guessedWord = string(word.length(), '-');
        int badGuessCount = 0;
        const int MAX_BAD_GUESS = 7;
        string badGuess;
        bool UseHint = false;
        do {
            renderGame( badGuessCount, guessedWord, badGuess);
            if (UseHint)
                cout << endl << hint <<endl;
            char guess = readAGuess();
            if (guess == '#')
            {
                UseHint = true;
                badGuessCount++;
            }
            else if (contains(word, guess)) {
                update(guessedWord, word, guess);
            } else {
                badGuessCount++;
                badGuess += guess;
            }
        } while (badGuessCount < MAX_BAD_GUESS && guessedWord != word);

        printGameOverInfo(badGuessCount, guessedWord, word);
        cout <<"\n";
        cout << "Do you want more (Y/N) ?";
        string answer;
        cin.ignore(1);
        getline(cin, answer);
        if (answer != "Y" && answer != "y")
            break;
    }
    ShowMenu();
}

//Load file hints
string FileHint(const string& fileName)
{
    if(fileName == "WordList/Animal/EASY.txt")
        return "WordList/Animal/EASY_HINT.txt";
    else if(fileName == "WordList/Animal/HARD.txt")
        return "WordList/Animal/HARD_HINT.txt";
    else if(fileName == "WordList/FoodAndDrink/EASY.txt")
        return "WordList/FoodAndDrink/EASY_HINT.txt";
    else if(fileName == "WordList/FoodAndDrink/HARD.txt")
        return "WordList/FoodAndDrink/HARD_HINT.txt";
}
