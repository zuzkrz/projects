#pragma once
#include "pch.h"
#include "Player.h"
class PlayerDatabase {
private:
	std::vector<Player> database;
public:
	PlayerDatabase();
	~PlayerDatabase();
	void createDatabase();
	void createPlayer(std::string nickt);
	bool doesPlayerExist(std::string nickt);
	int getID(std::string nickt);
	std::string getNick(int i);
	Player getPlayer(int i);
	void showPlayer(int i);
	void updatePlayer(int ID, int words, int letters);
	int size();
	void doesBetterExist(int currentID, bool& doesBetterExist, int& betterID);
	void rewriteDatabase();
};