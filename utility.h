#ifndef __UTILITY_H__
#define __UTILITY_H__
#include <string>

std::string normalize(const std::string& s);
std::string chooseWord(const std::string& fileName,const int& index);
bool contains(std::string word, char guess);
char readAGuess();
void Game();
void update(std::string& guessedWord, const std::string& word, char guess);
std::string ChooseTopic();
int ChooseIndex(const std::string& fileName);
std::string FileHint(const std::string& fileName);

#endif // __UTILITY_H__

