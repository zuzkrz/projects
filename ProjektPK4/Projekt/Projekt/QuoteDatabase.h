#pragma once
#include "pch.h"
#include "Quote.h"


class QuoteDatabase {
private:
	std::vector<Quote> database;
public:
	QuoteDatabase();
	~QuoteDatabase();
	void createDatabase();
	int getSize();
	void showData(int i);
	Quote getQuote(int i);
	int getWords(int ID);
	int getLetters(int ID);
};