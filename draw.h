#ifndef __DRAW_H__
#define __DRAW_H__

#include <string>

std::string getHangPicture(int badGuessCount);
void clearScreen();
void renderGame( int badGuessCount, std::string guessedWord, std::string badGuess = "");
void printGameOverInfo( int badGuessCount, std::string guessedWord, std::string word);
void ShowHeader();
void ShowMenu();
void HowToPlay();

#endif // __DRAW_H__

