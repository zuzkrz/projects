#pragma once
#include "pch.h"
#include "State.h"
#include "Panel.h"

class Help : public Panel {
private:
	//Sprite
	sf::Sprite BackgroundSprite;
	sf::Sprite helpinfo1Sprite;
	sf::Sprite helpinfo2Sprite;
	sf::Sprite helpinfo3Sprite;

	//Texture
	sf::Texture BackgroundTexture;
	sf::Texture helpinfo1;
	sf::Texture helpinfo2;
	sf::Texture helpinfo3;

	//GameState
	GameState state;

	//Events
	sf::Event ev;

	//Buttons
	sf::RectangleShape backButton;

	//Text and font
	sf::Font titleFont;
	sf::Font regularFont;
	sf::Text BackButtonText;
	sf::Text TitleText;

	//private functions
	void updateMousePosWindow(sf::RenderWindow* window);
	void initSprite();
	void initTexture();
	void initButton();
	void initFont();
	void initText();
	void initEnum();

	//mousePos
	sf::Vector2i mousePos;

	
public:
	Help();
	~Help();
	void draw(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	void pollEvents(sf::RenderWindow*& window);
	GameState returnGameState();
	void setState(GameState sentState);
	int currentPlayerID(int i);
	void updateDatabase(PlayerDatabase& data);
	bool isWon();
};