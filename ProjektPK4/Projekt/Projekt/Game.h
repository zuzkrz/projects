#pragma once
#include "pch.h"
#include "State.h"
#include "Login.h"
#include "Panel.h"
#include "PlayerDatabase.h"
#include "Player.h"
#include "Quote.h"
#include "QuoteDatabase.h"
#include "MainMenu.h"
#include "Statistics.h"
#include "Help.h"
#include "Play.h"



class Game
{
private:
	//Panels
	Panel* login;
	Panel* menu;
	Panel* stats;
	Panel* help;
	Panel* play;

	//Database
	PlayerDatabase Playerdata;
	int currentPlayerID;
	QuoteDatabase Quotedata;
	int currentQuote;

	//Gamestate
	GameState state;

	//window
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event ev;

	//mouse pos
	sf::Vector2i mousePosWindow;

	//icon image
	sf::Image icon;

	//private functions
	void initDatabase();
	void initPanels();
	void initVariables();
	void initWindow();
	void randomLevel();
	void initEnum();
	void updateMousePos();
	void initIcon();

public:
	//Constructors
	Game();
	~Game();

	//Functions
	bool running();
	void pollEvents();

	void update();
	void render();
};