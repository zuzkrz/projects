#include "pch.h"
#include "Keybord.h"

//Initializing Font
void Keyboard::initFont()
{
	if (!this->regularFont.loadFromFile("font/regularfont.ttf")) {
		std::cerr << "Couldn't load cryptofont!\n";
	}
}
//Method that prepares each key from keyboard to be drawn
void Keyboard::initKey()
{
	this->button.setPosition(x, y);
	this->button.setSize(sf::Vector2f(60.f, 40.f));
	this->button.setFillColor(sf::Color(138, 138, 138, 100));
	this->button.setOutlineColor(sf::Color::Black);
	this->button.setOutlineThickness(1.f);
}
//Updates Mouse Position on screen, takes reference to window
void Keyboard::updateMousePosWindow(sf::RenderWindow* window)
{
	this->mousePos = sf::Mouse::getPosition(*window);
}

Keyboard::Keyboard(float x, float y, char letter2)
{
	this->x = x;
	this->y = y;
	this->letter = letter2;
	this->ispressed = false;
	this->initFont();
	this->initKey();
}
//Method that returns shared_ptr to a text that will be drawn
std::shared_ptr<sf::Text> Keyboard::getText()
{
	std::shared_ptr<sf::Text> Letter = std::make_shared<sf::Text>();
	Letter->setFont(this->regularFont);
	Letter->setPosition(x + 20, y );
	std::string temp(1, letter);
	Letter->setString(temp);
	Letter->setFillColor(sf::Color::Black);
	Letter->setCharacterSize(30);
	return Letter;
}
//Method that returns button
sf::RectangleShape Keyboard::getButton()
{
	return this->button;
}
//Method that updates object in window
void Keyboard::update(sf::RenderWindow* window)
{
	this->updateMousePosWindow(window);
	if (mousePos.x >= x && mousePos.x <= x+60.f && mousePos.y >= y && mousePos.y <= y+40.f) {
		this->button.setOutlineThickness(2.f);
		this->button.setFillColor(sf::Color(138, 138, 138, 150));
	}
	else if (ispressed == true) {
		this->button.setOutlineThickness(2.f);
		this->button.setFillColor(sf::Color(138, 138, 138, 150));
	}
	else {
		this->button.setOutlineThickness(1.f);
		this->button.setFillColor(sf::Color(138, 138, 138, 100));
	}
}
//Method that checks if key is pressed
bool Keyboard::isPressed()
{
	if (this->ispressed == true) {
		return true;
	}
	else {
		return false;
	}
}
//Method that returns current letter pressed
char Keyboard::letterPressed()
{
	return letter;
}
//Method that returns X position
float Keyboard::getX()
{
	return x;
}
//Method that returns Y position
float Keyboard::getY()
{
	return y;
}
//Method that updates if key is pressed
void Keyboard::updatebool(bool &temp)
{
	this->ispressed = temp;
}
