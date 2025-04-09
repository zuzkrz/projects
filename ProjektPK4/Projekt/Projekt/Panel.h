#pragma once
#include "pch.h"
#include "State.h"
#include "PlayerDatabase.h"
#include "Player.h"

class Panel
{
public:
	Panel() {};
	virtual ~Panel() {};
	virtual void draw(sf::RenderWindow*& window) = 0;
	virtual void update(sf::RenderWindow* window) = 0;
	virtual void pollEvents(sf::RenderWindow*& window) = 0;
	virtual GameState returnGameState() = 0;
	virtual void setState(GameState sentState) = 0;
	virtual void updateMousePosWindow(sf::RenderWindow* window) = 0;
	virtual int currentPlayerID(int i) = 0;
	virtual void updateDatabase(PlayerDatabase& data) = 0;
	virtual bool isWon() = 0;
};