#pragma once
#include "pch.h"
#include "State.h"
#include "Panel.h"


class Main : public Panel {
private: 
	//Variables
	std::vector<sf::Text>animetedLetters;

	//player database
	PlayerDatabase database;
	int currentID;

	//Sprite
	sf::Sprite LoginBackgroundSprite;
	sf::Sprite helpSprite;

	//Texture
	sf::Texture LoginBackgroundTexture;
	sf::Texture helpTexture;
	sf::Texture helpColorTexture;

	//GameState
	GameState state;

	//Events
	sf::Event ev;

	//Buttons
	sf::RectangleShape PlayButton;
	sf::RectangleShape exitButton;
	sf::RectangleShape statisticsButton;


	//Text and font
	sf::Font titleFont;
	sf::Font regularFont;
	sf::Text TitleText;
	sf::Text welcomeText;
	sf::Text playButtonText;
	sf::Text statisticsButtonText;
	sf::Text exitButtonText;


	//Private function
	void initEnum();
	void initSprite();
	void initTexture();
	void initButton();
	void initFont();
	void initText();
	void initVariables();
	void updateMousePosWindow(sf::RenderWindow* window);
	//mousePos
	sf::Vector2i mousePos;
public:
	Main();
	~Main();
	void draw(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	void pollEvents(sf::RenderWindow*& window);
	GameState returnGameState();
	void setState(GameState sentState);
	int currentPlayerID(int id);
	void updateDatabase(PlayerDatabase& data);
	bool isWon();
	
};