#pragma once

#include "pch.h"
#include "State.h"
#include "Panel.h"
#include "Keybord.h"
#include "QuoteDatabase.h"
#include "Letter.h"



class Play : public Panel {
private:
	//database 
	QuoteDatabase database;
	int currentQuoteID;
	Quote currentQuote;

	//GameState
	GameState state;

	//Sprite & Buttons
	sf::Sprite BackgroundSprite;
	sf::Sprite pauseSprite;
	sf::Sprite life1;
	sf::Sprite life2;
	sf::Sprite life3;
	sf::RectangleShape pauseBlock;
	sf::RectangleShape pauseBack;
	sf::RectangleShape pauseMain;
	sf::RectangleShape endReplay;
	sf::RectangleShape endMain;

	//Texture
	sf::Texture BackgroundTexture;
	sf::Texture pauseTexture;
	sf::Texture pauseOnTexture;
	sf::Texture heartTexture;
	sf::Texture heartLostTexture;
	sf::Texture lock1;		//1
	sf::Texture unlocked1;	//3
	sf::Texture lock2;		//2
	sf::Texture lock2Right;	//4
	sf::Texture lock2Left;	//5
	sf::Texture unlocked2;	//6
	std::vector<std::shared_ptr<sf::Sprite>> locks;

	//Font and Text
	sf::Font regularFont;
	sf::Text pauseBackText;
	sf::Text pauseMainText;
	sf::Text pauseText;
	sf::Text endGameText;
	sf::Text endMainText;
	sf::Text endReplayText;

	//Events
	sf::Event ev;

	//Letters and Keybord
	std::vector<Letter> vecLetters;
	std::vector<Keyboard> keyboard;

	// Variables
	std::vector<char> differentLetters;
	std::vector<int> howManyLetters;
	std::vector<int> assignedNumber;
	std::vector<int> LockPos, LockPosForvecLetter;
	int life, difficulty;
	char currentKey;
	bool isPressedKey;
	bool isGameOver;
	bool isPaused;
	bool won;

	//mousePos
	sf::Vector2i mousePos;

	//private functions
	void updateMousePosWindow(sf::RenderWindow* window);
	void initTexture();
	void initSprite();
	void initEnum();
	void initPause();
	void clean();
	void initFont();
	void initKeyboard();
	void assignNumber();
	void initQuote();
	void initLetters();
	void updateVectors(char passed);
	void updateLetter(char passed);
	void allLivesLost();
	void checkIfFinished();
	void prepareLockPos();
	void endGame();
	void checkForUnlocked();
	void setCorrectTexture(int no, sf::Sprite& sprite);
	void updateTexture();

public:
	Play(QuoteDatabase & data);
	~Play();
	void draw(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	void pollEvents(sf::RenderWindow*& window);
	GameState returnGameState();
	void setState(GameState sentState);
	int currentPlayerID(int i);
	void updateDatabase(PlayerDatabase& data);
	bool isWon();
};