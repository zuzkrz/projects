#pragma once
#include "pch.h"

class Keyboard {
private:
	//Variables
	float x, y;
	bool ispressed;
	char letter;

	//Button and Font
	sf::RectangleShape button;
	sf::Font regularFont;

	//Mouse Position
	void updateMousePosWindow(sf::RenderWindow* window);
	sf::Vector2i mousePos;
	
	//Private functions
	void initFont();
	void initKey();
public:
	Keyboard(float x, float y, char letter);
	std::shared_ptr<sf::Text> getText();
	sf::RectangleShape getButton();
	void update(sf::RenderWindow* window);
	bool isPressed();
	char letterPressed();
	float getX();
	float getY();
	void updatebool(bool &temp);
};