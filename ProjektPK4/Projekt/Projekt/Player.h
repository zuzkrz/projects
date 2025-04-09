#pragma once
#include "pch.h"

class Player {
private:
	std::string nick;
	int levels, words, letters;
public:
	Player(std::string nickt);
	Player(std::string nickt, int lvl ,int wor, int lett);
	~Player();
	std::string getNick();
	int getLvl();
	int getWords();
	int getLetters();
	void updatePlayer(int lvl, int w, int l);
};