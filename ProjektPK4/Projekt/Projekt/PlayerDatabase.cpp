#include "pch.h"
#include "PlayerDatabase.h"
PlayerDatabase::PlayerDatabase()
{
}

PlayerDatabase::~PlayerDatabase()
{
}
//Method that creates database based on values from file
void PlayerDatabase::createDatabase()
{
	std::ifstream plik;
	plik.open("database/player.txt");
	if (plik.is_open()) {
		std::vector<std::string> Vnick;
		std::vector<int> Vlvl;
		std::vector<int> Vw;
		std::vector<int> Vl;
		std::string line;
		int temp5 = 1;

		while (std::getline(plik, line)) {
			int temp = 1;
			if (temp5 == 1) {
				Vnick.push_back(line);
				temp5++;
			}
			else {
				std::stringstream ss(line);
				int temp2 = 0;
				int poziom = 0;
				int wyraz = 0;
				int litera = 0;
				while (ss >> temp2) {
					if (temp == 1) {
						poziom = temp2;
						temp++;
					}
					else if (temp == 2) {
						wyraz = temp2;
						temp++;
					}
					else {
						litera = temp2;
						temp = 1;
					}

				}
				Vlvl.push_back(poziom);
				Vw.push_back(wyraz);
				Vl.push_back(litera);
				temp5--;
			}
		}
		for (int k = 0; k < Vnick.size(); k++) {
			database.push_back(Player(Vnick[k], Vlvl[k], Vw[k], Vl[k]));
		}
		plik.close();
	}
}

//Method that creates new player and rewrites database to stay up to date
void PlayerDatabase::createPlayer(std::string nickt)
{
	database.push_back(Player(nickt));
	rewriteDatabase();
}
//Method that checks if player of passed nick exists
bool PlayerDatabase::doesPlayerExist(std::string nickt)
{
	bool temp = false;
	for (auto i : database) {
		if (i.getNick() == nickt) temp = true;
	}
	return temp;
}
//Method that returns ID of a player whose nick is same as passed value
int PlayerDatabase::getID(std::string nickt)
{
	for (int i = 0; i < database.size(); i++) {
		if (database[i].getNick() == nickt) {
			return i;
		}
	}
	return -1;
}
//Method that returns nick whose ID is same as passed value
std::string PlayerDatabase::getNick(int i)
{
	return database[i].getNick();
}
//Method that returns player whose ID is same as passed value
Player PlayerDatabase::getPlayer(int i)
{
	Player temp(database[i].getNick(), database[i].getLvl(), database[i].getWords(), database[i].getLetters());
	return temp;
}
//Method that shows player whose ID is same as passed value
void PlayerDatabase::showPlayer(int i)
{
	std::cout << database[i].getNick() << " " << database[i].getLvl() << " " << database[i].getWords() << " " << database[i].getLetters() << std::endl;
}
//Method that updates player whose ID is same as passed value
void PlayerDatabase::updatePlayer(int ID, int words, int letters)
{
	this->database[ID].updatePlayer(1, words, letters);
	rewriteDatabase();
}
//Method that returns size of database
int PlayerDatabase::size()
{
	return database.size();
}
//Method that checks if there is better player 
void PlayerDatabase::doesBetterExist(int currentID, bool& doesBetterExist, int& betterID)
{
	int tempLVL = database[currentID].getLvl();
	for (int i = 0; i < database.size(); i++) {
		if (database[i].getLvl() > tempLVL) {
			doesBetterExist = true;
			betterID = i;
		}
	}
}
//Method that rewrites database
void PlayerDatabase::rewriteDatabase() {
	std::ofstream ofs("database/player.txt", std::ofstream::trunc);									
	for (int i = 0; i < database.size(); i++) {													
		std::string newPlayer;
		newPlayer = database[i].getNick()+"\n"+std::to_string(database[i].getLvl())+" "+ std::to_string(database[i].getWords()) + " " + std::to_string(database[i].getLetters());
		if (i != database.size() - 1) {
			newPlayer = newPlayer + "\n";
		}
		ofs << newPlayer;																	
	}
	ofs.close();
}
