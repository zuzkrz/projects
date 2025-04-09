#pragma once
#include "pch.h"

class Letter {
private:
	//Variables
	float x, y;
	bool isdone, alldone, isLock;
	char letter;
	int number;
	int difficulty;
	int whichTexture;

	//Font, button and line
	sf::RectangleShape button;
	sf::RectangleShape line;
	sf::Font regularFont;

	//Textures & sprite
	sf::Texture lock1;		//1
	sf::Texture unlocked1;	//3
	sf::Texture lock2;		//2
	sf::Texture lock2Right;	//4
	sf::Texture lock2Left;	//5
	sf::Texture unlocked2;	//6
	sf::Sprite lock;

	//Mouse Position
	void updateMousePosWindow(sf::RenderWindow* window);
	sf::Vector2i mousePos;

	//Private functions
	void initTextures();
	void initFont();
	void initLetter();
public:
	Letter(float x, float y, char letter, bool isdone, int num);
	Letter(float x, float y, char letter, bool isdone, int num, bool isLocked, int difficulty);
	std::shared_ptr<sf::Text> getText();
	std::shared_ptr<sf::Text> getNum();
	sf::Sprite getLock();
	sf::RectangleShape getButton();
	sf::RectangleShape getLine();
	void update(sf::RenderWindow* window);
	bool isCorrect(char passed);
	float getX();
	float getY();
	void updatebool(bool& temp);
	void wrongLetter(int i);
	bool isDone();
	char getLetter();
	void allDone();
	bool isLocked();
	void updateLockStatus(bool left, bool right);
	void updateLockStatus(int left, bool right);
	void updateLockStatus(bool left, int right);
	int correctTexture();
	void draw(sf::RenderWindow*& window);
};