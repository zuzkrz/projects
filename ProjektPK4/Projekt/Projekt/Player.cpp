#include "pch.h"
#include "Player.h"
Player::Player(std::string nickt)
{
	this->nick = nickt;
	this->levels = 0;
	this->letters = 0;
	this->words = 0;
}

Player::Player(std::string nickt, int lvl, int wor, int lett)
{
	this->nick = nickt;
	this->levels = lvl;
	this->letters = lett;
	this->words = wor;
}

Player::~Player()
{
}
//Method that returns player nick
std::string Player::getNick()
{
	return nick;
}
//Method that returns number of level won
int Player::getLvl()
{
	return levels;
}
//Method that returns number of words guessed
int Player::getWords()
{
	return words;
}
//Method that returns number of letters guessed
int Player::getLetters()
{
	return letters;
}
//Method that updates player based on sent data
void Player::updatePlayer(int lvl, int w, int l)
{
	this->levels = levels + lvl;
	this->words = words + w;
	this->letters = letters + l;
}
