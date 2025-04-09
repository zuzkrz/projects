#include "pch.h"
#include "QuoteDatabase.h"
QuoteDatabase::QuoteDatabase()
{
}

QuoteDatabase::~QuoteDatabase()
{
}
//Method that creates database based on values from file
void QuoteDatabase::createDatabase()
{
	std::ifstream plik;
	plik.open("database/Quotes.txt");
	if (plik.is_open()) {
		std::vector<std::vector<char>> Vquote;
		std::vector<std::string> Vauthor;
		std::vector<std::vector<bool>> Vbool;
		std::vector<std::vector<int>> intVec;
		std::string line;
		int tem = 1;

		while (std::getline(plik, line)) {   // wczytywanie lini z pliku

			if (tem == 1) {
				std::string temp = line;
				std::vector<char> temp1(temp.begin(), temp.end());
				Vquote.push_back(temp1);
				tem++;
			}
			else if (tem == 2) {
				std::stringstream ss(line);
				std::vector<int> temp;
				int temp1;
				while (ss >> temp1) {
					temp.push_back(temp1);
				}
				intVec.push_back(temp);
				tem++;
			}
			else {
				Vauthor.push_back(line);
				tem--;
				tem--;
			}
		}

		for (int z = 0; z < Vquote.size(); z++) {  // wprowadzenie true/false do wektora
			std::vector<bool> temp3;
			for (int t = 0; t < Vquote[z].size(); t++) {
				if (Vquote[z][t] == ' ') {
					temp3.push_back(true);
				}
				else {
					temp3.push_back(false);
				}
			}
			for (int t = 0; t < intVec[z].size(); t++) {
				temp3[intVec[z][t]] = true;
			}
			Vbool.push_back(temp3);
		}
		if (Vquote.size() == Vauthor.size() && Vquote.size() == Vbool.size()) {
			for (int k = 0; k < Vquote.size(); k++) {
				database.push_back(Quote(Vquote[k], Vbool[k], Vauthor[k]));
			}
		}
		else std::cerr << "\nThere is something wrong with a file!\n";

		plik.close();
	}
	else {
		std::cout << "Could not open 'Quotes.txt' file.";
	}
}
//Method that returns size of database
int QuoteDatabase::getSize()
{
	return this->database.size();
}
//Method that shows particular Quote
void QuoteDatabase::showData(int i)
{
	std::cout << database[i].getquote() << std::endl << database[i].getAuthor() << std::endl;
}
//Method that returns Quote
Quote QuoteDatabase::getQuote(int i)
{
	Quote temp(database[i].getQuote(),database[i].isDone(), database[i].getAuthor());
	return temp;
}
//Method that returns number of words in quote
int QuoteDatabase::getWords(int ID)
{
	return this->database[ID].getWords();
}
//Method that returns number of letters in quote
int QuoteDatabase::getLetters(int ID)
{
	return this->database[ID].getLetters();
}
