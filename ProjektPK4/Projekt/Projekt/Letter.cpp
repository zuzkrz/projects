#include "pch.h"
#include "Letter.h"

//Method that returns shared_ptr to a number that will be drawn
std::shared_ptr<sf::Text> Letter::getNum()
{
	std::shared_ptr<sf::Text> Letter = std::make_shared<sf::Text>();
	Letter->setFont(this->regularFont);
	if (number > 9) {
		Letter->setPosition(x + 7, y + 35);
	}
	else {
		Letter->setPosition(x + 12, y + 35);
	}
	if (this->alldone == false) {
		Letter->setString(std::to_string(this->number));
	}
	else {
		Letter->setString("");
	}
	Letter->setFillColor(sf::Color::Black);
	Letter->setCharacterSize(17);
	return Letter;
}
sf::Sprite Letter::getLock()
{
	return this->lock;
}
//Method that returns button
sf::RectangleShape Letter::getButton()
{
	return this->button;
}
//Method that returns line
sf::RectangleShape Letter::getLine()
{
	return this->line;
}
//Method that updates object in window
void Letter::update(sf::RenderWindow* window)
{
	this->updateMousePosWindow(window);
	if (this->isdone == false && isLock == false) {
		if (mousePos.x >= x && mousePos.x <= x + 30.f && mousePos.y >= y && mousePos.y <= y + 60.f) {
			this->button.setOutlineThickness(2.f);
		}
		else {
			this->wrongLetter(2);
			this->button.setOutlineThickness(0.f);
		}
	}
	else {
		this->button.setOutlineThickness(0.f);
	}
}
//Method that checks is letter is guessed correctly
bool Letter::isCorrect(char passed)
{
	if (passed == this->letter) {
		this->isdone = true;
		return true;
	}
	else if (passed == ' ') {
		return true;
	}
	else {
		return false;
	}
}
//Method that returns X position
float Letter::getX()
{
	return x;
}
//Method that returns Y position
float Letter::getY()
{
	return y;
}
//Method that updates if letter is guessed
void Letter::updatebool(bool& temp)
{
	this->isdone = temp;
}
//Method that makes the outline red if trying to guess letter was not positive
void Letter::wrongLetter(int i)
{
	if (i ==1)
		this->button.setOutlineColor(sf::Color::Red);
	else 
		this->button.setOutlineColor(sf::Color::Green);
}
//Method that returns if letter is guessed
bool Letter::isDone()
{
	return this->isdone;
}
//Method that returns if letter
char Letter::getLetter()
{
	return this->letter;
}
//Method that returns if every letter of same 'kind' have been guessed
void Letter::allDone()
{
	this->alldone = true;
}
//Returns true if letter is locked
bool Letter::isLocked()
{
	return this->isLock;
}
void Letter::updateLockStatus(bool left, bool right)
{
	if (isLock == true) {
		if (difficulty == 2) {
			if (left == true && right == true) {
				this->isLock = false;
				this->lock.setTexture(this->unlocked2);
				this->whichTexture = 6;
			}
			else if (left == false && right == true) {
				this->whichTexture = 4;
				this->lock.setTexture(this->lock2Right);
			}
			else if (left == true && right == false) {
				this->whichTexture = 5;
				this->lock.setTexture(this->lock2Left);
			}
		}
		if (difficulty == 1) {
			if (left == true) {
				this->whichTexture = 3;
				this->lock.setTexture(this->unlocked1);
				this->isLock = false;
			}
			else if (right == true) {
				this->whichTexture = 3;
				this->lock.setTexture(this->unlocked1);
				this->isLock = false;
			}
		}
	}
}
void Letter::updateLockStatus(int left, bool right)
{
	if (isLock == true) {
		if (right == true) {
			this->whichTexture = 3;
			this->lock.setTexture(this->unlocked1);
			this->isLock = false;
		}
	}
}
void Letter::updateLockStatus(bool left, int right)
{
	if (isLock == true) {
		if (left == true) {
			this->whichTexture = 3;
			this->lock.setTexture(this->unlocked1);
			this->isLock = false;
		}
	}
}
int Letter::correctTexture()
{
	return whichTexture;
}
void Letter::draw(sf::RenderWindow*& window)
{
	window->draw(this->lock);
}
//Updates Mouse Position on screen, takes reference to window
void Letter::updateMousePosWindow(sf::RenderWindow* window)
{
	this->mousePos = sf::Mouse::getPosition(*window);
}
//Initializing Texture
void Letter::initTextures()
{
	if (!this->lock1.loadFromFile("png/lock1.png")) {
		std::cerr << "Couldn't load lock1!\n";
	}
	if (!this->unlocked1.loadFromFile("png/lock1G.png")) {
		std::cerr << "Couldn't load lock1G!\n";
	}
	if (!this->lock2.loadFromFile("png/lock2.png")) {
		std::cerr << "Couldn't load lock1!\n";
	}
	if (!this->unlocked2.loadFromFile("png/lock2G.png")) {
		std::cerr << "Couldn't load lock2G!\n";
	}
	if (!this->lock2Right.loadFromFile("png/lock2R.png")) {
		std::cerr << "Couldn't load lock1R!\n";
	}
	if (!this->lock2Left.loadFromFile("png/lock2L.png")) {
		std::cerr << "Couldn't load lock1L!\n";
	}
}
//Initializing Font
void Letter::initFont()
{
	if (!this->regularFont.loadFromFile("font/regularfont.ttf")) {
		std::cerr << "Couldn't load cryptofont!\n";
	}
}
//Initializing Letter
void Letter::initLetter()
{
	if (this->difficulty == 1 && this->isLock == true) {
		this->lock.setTexture(this->lock1);
		this->lock.setPosition(x, y);
	}
	else if (this->difficulty == 2 && this->isLock == true) {
		this->lock.setTexture(this->lock2);
		this->lock.setPosition(x, y);
	}
	this->button.setPosition(x, y);
	this->button.setSize(sf::Vector2f(30.f, 60.f));
	this->button.setFillColor(sf::Color(138, 138, 138, 0));
	this->button.setOutlineColor(sf::Color::Green);
	this->line.setPosition(x + 1.f, y + 35.f);
	this->line.setSize(sf::Vector2f(28.f, 2.f));
	this->line.setFillColor(sf::Color::Black);
}

Letter::Letter(float x, float y, char letter, bool isdone, int num)
{
	this->difficulty = 0;
	this->isLock = false;
	this->alldone = false;
	this->x = x;
	this->y = y;
	this->letter = letter;
	this->isdone = isdone;
	this->number = num;
	this->initFont();
	this->initLetter();
	this->initTextures();
}
Letter::Letter(float x, float y, char letter, bool isdone, int num, bool isLocked, int difficulty)
{
	this->difficulty = difficulty;
	if (difficulty == 1) whichTexture = 1;
	else if (difficulty == 2) whichTexture = 2;
	this->isLock = isLocked;
	this->alldone = false;
	this->x = x;
	this->y = y;
	this->letter = letter;
	this->isdone = isdone;
	this->number = num;
	this->initFont();
	this->initLetter();
	this->initTextures();
}
//Method that returns shared_ptr to a letter that will be drawn
std::shared_ptr<sf::Text> Letter::getText()
{
	std::shared_ptr<sf::Text> Letter = std::make_shared<sf::Text>();
	Letter->setFont(this->regularFont);
	Letter->setPosition(x + 7.f, y+5.f);
	if(this->isdone == true){
	Letter->setString(this->letter);
	}
	Letter->setFillColor(sf::Color::Black);
	Letter->setCharacterSize(25);
	return Letter;
}

