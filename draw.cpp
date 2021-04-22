#include <iostream>
#include <cstdlib>
#include <vector>
#include <thread>
#include <conio.h>
#include "utility.h"
#include "draw.h"

using namespace std;


string getHangPicture(int badGuessCount)
{
    string picture[] = {"",
"   ------------\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |          |\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",

};
    return picture[badGuessCount];
}

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif // _WIN32
}

void renderGame(int badGuessCount, string guessedWord, string badGuess)
{
    clearScreen();
    cout << "Current guess = " << guessedWord << endl;
    cout << "You have made bad " << badGuessCount << " guess(es)"
         << (badGuess.empty() ? "" : ": ") << badGuess << endl
         << getHangPicture(badGuessCount) << endl;
}

const vector<string> HANGED = {
"   ------------\n"
"   |         /\n"
"   |        O\n"
"   |       /|\\\n"
"   |       / \\\n"
"   |         \n"
"   |         \n"
"   |         \n"
"   |         \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |           \\\n"
"   |            O\n"
"   |           /|\\\n"
"   |           / \\\n"
"   |             \n"
"   |             \n"
"   |             \n"
"   |             \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        "
};

void printGameOverInfo( int badGuessCount, string guessedWord, string word)
{
    int CountTime = 0;
    renderGame( badGuessCount, guessedWord);
    if (guessedWord != word) {
        int n = 0;
        while (true) {
            clearScreen();
            cout << "Game Over!!! You are hanged" << endl
                 << "The correct word is " << word << endl;
            cout << HANGED[n];
            n = (n+1) % HANGED.size();

            //count down
            cout <<endl <<"Wait for " << 10-CountTime <<" second to restart";

            std::this_thread::sleep_for (std::chrono::milliseconds(500));
            CountTime ++;
            if (CountTime > 10)
                break;
        }
        cout << "";

    } else {
        cout << "Congrats!!! You are free" << endl;
    }
}

void ShowHeader() //the function which shows the header on each screen
{
	clearScreen();
	cout<<endl<<"+-----------------------------------------------------------------------------+";
	cout<<endl<<"|                          Hangman Game - Le Tuan Anh                         |";
	cout<<endl<<"+-----------------------------------------------------------------------------+";
	cout<<endl<<endl;
	return;
}

void HowToPlay() //how to play option
{
	ShowHeader();
	cout<<"What...You've never played hangman! Seriously? Sigh...";
	cout<<"\n\nHere's how to play: ";
	cout<<"\n - Try to solve the riddle before your chances run out.";
	cout<<"\n - Type in the letters you wish to guess. Careful! Wrong letters lose chances.";
	cout<<"\n - Type in # to use hint.";
	cout<<"\n\n\t\t\t\t    Press any key to go back to main menu...";
	_getch();
	ShowMenu();
}

void ShowMenu() //this is the main menu of the program
{
	char choice; //to store choice
	ShowHeader();
	cout<<HANGED[1]<<endl;
	cout<<"Select an Option: ";
	cout<<"\n1. Start Game";
	cout<<"\n2. How to play";
	cout<<"\n3. Exit";
	cout<<endl<<"\t\tChoice: ";
	cin >> choice; //Input function returns input values

	if(choice == '1') Game(); //start game
	else if(choice == '2') HowToPlay(); //how to play option
	else if(choice == '3') //exit program
	{
		cout<<"\t\tExited succesfully!";
		_getch();
		exit(0);
	}
	else
	{
		cout<<"\t\tInvalid Input! Try again.";
		_getch();
		ShowMenu();
	}
}


