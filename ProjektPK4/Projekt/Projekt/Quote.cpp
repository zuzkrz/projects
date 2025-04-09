#include "pch.h"
#include "Quote.h"

//Method that returns string of quote
std::string Quote::getquote()
{
	std::string temp;
	for (auto& i : quote) {
		temp = temp + i;
	}
	return temp;
}
//Method that returns vector<char> of sorted quote
std::vector<char> Quote::getSortedQuote()
{
	std::vector<char> temp = this->quote;
	std::ranges::sort(temp, std::ranges::greater{});
	return temp;
}

Quote::Quote()
{
}
Quote::Quote(std::vector<char> quotet, std::vector<bool> is_donet, std::string authort)
{
	this->quote = quotet;
	this->is_done = is_donet;
	this->author = authort;
	std::string temp(quotet.begin(), quotet.end());
	std::stringstream ss(temp);
	int temp2 = 0;
	for (auto i : is_donet) {
		if (i == true) temp2++;
	}
	int tempLetters=0;
	for (auto i : quotet) {
		if (i != ' ') {
			tempLetters++;
		}
	}
	tempLetters = tempLetters - temp2;
	this->letters = tempLetters;
	temp.clear();
	tempLetters = 0;
	while (ss >> temp) {
		tempLetters++;
	}
	this->words = tempLetters;
}
Quote::~Quote()
{
}
//Method that returns vector<char> of quote
std::vector<char> Quote::getQuote()
{
	return this->quote;
}
//Method that returns vector<bool> of done or not letters
std::vector<bool> Quote::isDone()
{
	return this->is_done;
}
//Method that returns author
std::string Quote::getAuthor()
{
	return this->author;
}
//Method that returns number of words in quote
int Quote::getWords()
{
	return this->words;
}
//Method that returns number of letters in quote
int Quote::getLetters()
{
	return this ->letters;
}

