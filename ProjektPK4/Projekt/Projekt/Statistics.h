#pragma once
#include "pch.h"
#include "Panel.h"
#include "PlayerDatabase.h"
#include "Player.h"

class Statistics :
    public Panel
{
private:
	//player database
	PlayerDatabase database;
	int playerID;

	//Sprite
	sf::Sprite BackgroundSprite;

	//Texture
	sf::Texture BackgroundTexture;

	//GameState
	GameState state;

	//Variables
	bool isCurrentBest;
	bool isdatabaseupdated;

	//Events
	sf::Event ev;

	//Buttons
	sf::RectangleShape backButton;

	//Text and font
	sf::Font titleFont;
	sf::Font regularFont;
	sf::Text TitleText;
	sf::Text BackButtonText;
	sf::Text yourStats;
	sf::Text Lvl;
	sf::Text Words;
	sf::Text Letters;
	sf::Text currentNick;
	sf::Text currentLvl;
	sf::Text currentW;
	sf::Text currentL;
	sf::Text BestNick;
	sf::Text BestLvl;
	sf::Text BestW;
	sf::Text BestL;
	sf::Text BestPlayer;
	sf::Text YouBest;

	//Private function
	void initEnum();
	void initSprite();
	void initTexture();
	void initButton();
	void initFont();
	void initText();
	void fillStats();
	
	void updateMousePosWindow(sf::RenderWindow* window);

	//mousePos
	sf::Vector2i mousePos;

public:
	Statistics(PlayerDatabase &data, int temp);
	~Statistics();
	void draw(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	void pollEvents(sf::RenderWindow*& window);
	GameState returnGameState();
	void setState(GameState sentState);
	int currentPlayerID(int id);
	void updateDatabase(PlayerDatabase& data);
	bool isWon();
};

