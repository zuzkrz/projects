#pragma once
#include "pch.h"

class Quote {
private:
	std::vector<char> quote;
	std::vector<bool> is_done;
	std::string author;
	int words, letters;
	
public:
	Quote();
	Quote(std::vector<char> quotet, std::vector<bool> is_donet, std::string authort);
	~Quote();
	std::vector<char> getQuote();
	std::vector<bool> isDone();
	std::string getAuthor();
	int getWords();
	int getLetters();
	std::string getquote();
	std::vector<char> getSortedQuote();
};