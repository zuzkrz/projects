#pragma once
#include "pch.h"
#include "State.h"
#include "Panel.h"
#include "PlayerDatabase.h"
#include "Player.h"


class Login : public Panel {
private:
	//Player database
	PlayerDatabase database;
	int playerID;

	//Sprite
	sf::Sprite LoginBackgroundSprite;

	//Texture
	sf::Texture LoginBackgroundTexture;

	//GameState
	GameState state;

	//Events
	sf::Event ev;

	//Variables
	bool isNewClicked;
	bool isLoginValid;

	//Buttons
	sf::RectangleShape LoginButton;
	sf::RectangleShape exitButton;
	sf::RectangleShape checkBox;

	//Textbox
	sf::RectangleShape TextBox;
	bool isTextBoxClicked;

	//Text and font
	std::string newNick;
	sf::Font titleFont;
	sf::Font regularFont;
	sf::Text TitleText;				
	sf::Text exitButtonText;
	sf::Text loginButtonText;
	sf::Text tick;				
	sf::Text checkBoxText;		
	sf::Text welcomeText;		
	sf::Text Nick;				
	sf::Text ValidationInfo;
	sf::Text errorLoginText;

	//Private function
	void initEnum();
	void initSprite();
	void initTexture();
	void initTextBox();
	void initButton();
	void initFont();
	void initText();
	void initVariables();
	int isNickValid();
	void updateMousePosWindow(sf::RenderWindow* window);
	//mousePos
	sf::Vector2i mousePos;


	
public:
	Login(PlayerDatabase& data);
	~Login();
	int  currentPlayerID(int id);
	void draw(sf::RenderWindow*& window);
	void update(sf::RenderWindow* window);
	void pollEvents(sf::RenderWindow*& window);
	GameState returnGameState();
	void setState(GameState sentState);
	virtual void updateDatabase(PlayerDatabase& data);
	bool isWon();
};