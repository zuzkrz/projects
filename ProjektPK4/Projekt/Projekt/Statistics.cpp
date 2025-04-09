#include "pch.h"
#include "Statistics.h"

Statistics::Statistics(PlayerDatabase& data, int temp)
{
	this->isCurrentBest = false;
	this->isdatabaseupdated = false;
	this->database = data;
	this->playerID = temp;
	this->initButton();
	this->initEnum();
	this->initFont();
	this->initTexture();
	this->initSprite();
	this->initText();
}

Statistics::~Statistics()
{
}
//Method that draws object in window
void Statistics::draw(sf::RenderWindow*& window)
{
	window->draw(this->BackgroundSprite);
	window->draw(this->TitleText);
	window->draw(this->backButton);
	window->draw(this->BackButtonText);
	window->draw(this->yourStats);
	window->draw(this->Lvl);
	window->draw(this->Words);
	window->draw(this->Letters);
	window->draw(this->BestPlayer);
	if (isdatabaseupdated) {
		window->draw(this->currentNick);
		window->draw(this->currentLvl);
		window->draw(this->currentW);
		window->draw(this->currentL);
		if (isCurrentBest == false) {
			window->draw(this->BestNick);
			window->draw(this->BestLvl);
			window->draw(this->BestW);
			window->draw(this->BestL);
		}
		else {
			window->draw(this->YouBest);
		}
	}
}
//Method that updates object in window
void Statistics::update(sf::RenderWindow* window)
{
	this->updateMousePosWindow(window);
	if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 585.f && mousePos.y <= 655.f) {
		this->backButton.setOutlineThickness(2.f);
		this->backButton.setFillColor(sf::Color(138, 138, 138, 150));
	}
	else {
		this->backButton.setOutlineThickness(1.f);
		this->backButton.setFillColor(sf::Color(138, 138, 138, 100));
	}
}
//Method that checks if there are any actions preform in a window.
void Statistics::pollEvents(sf::RenderWindow*& window)
{
	while (window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 585.f && mousePos.y <= 655.f) {
				this->state = GameState::MAIN;
			}
			break;
		}
	}
}
//Method that returns gamestate
GameState Statistics::returnGameState()
{
	return this->state;
}
//Method that sets gamestate
void Statistics::setState(GameState sentState)
{
	this->state = sentState;
}
//Method that gets id for a current player from passed value
int Statistics::currentPlayerID(int id)
{
	this->playerID = id;
	fillStats();
	isdatabaseupdated = true;
	
	return 0;
}
//Method that updates database if a new player has logged in
void Statistics::updateDatabase(PlayerDatabase& data)
{
	this->database = data;
}
//Method that does nothing.
bool Statistics::isWon()
{
	return false;
}
//Initializing gamestate to STATISTICS
void Statistics::initEnum()
{
	this->state = GameState::STATISTICS;
}
//Initializing Sprites
void Statistics::initSprite()
{
	this->BackgroundSprite.setTexture(this->BackgroundTexture);
}
//Initializing Textures
void Statistics::initTexture()
{
	if (!this->BackgroundTexture.loadFromFile("png/statsbckgrnd.png")) {
		std::cerr << "Couldn't load LoginBackground!\n";
	}
}
//Initializing Buttons
void Statistics::initButton()
{
	this->backButton.setPosition(600.f, 585.f);
	this->backButton.setSize(sf::Vector2f(300.f, 70.f));
	this->backButton.setFillColor(sf::Color(138, 138, 138, 100));
	this->backButton.setOutlineColor(sf::Color::Black);
	this->backButton.setOutlineThickness(1.f);
}
//Initializing Font
void Statistics::initFont()
{
	if (!this->titleFont.loadFromFile("font/cryptofont.otf")) {
		std::cerr << "Couldn't load cryptofont!\n";
	}
	if (!this->regularFont.loadFromFile("font/regularfont.ttf")) {
		std::cerr << "Couldn't load cryptofont!\n";
	}
}
//Initializing Text
void Statistics::initText()
{
	this->TitleText.setFont(this->titleFont);
	this->TitleText.setPosition(550.f, 50.f);
	this->TitleText.setFillColor(sf::Color::Black);
	this->TitleText.setString("STATISTICS");
	this->TitleText.setCharacterSize(100);
	this->BackButtonText.setFont(this->regularFont);
	this->BackButtonText.setPosition(680.f, 600.f);
	this->BackButtonText.setFillColor(sf::Color::Black);
	this->BackButtonText.setString("GO BACK");
	this->yourStats.setFont(this->regularFont);
	this->yourStats.setPosition(150.f, 160.f);
	this->yourStats.setFillColor(sf::Color::Black);
	this->yourStats.setString("Your statistics:");
	this->yourStats.setCharacterSize(25);
	this->Lvl.setFont(this->regularFont);
	this->Lvl.setPosition(400.f, 180.f);
	this->Lvl.setFillColor(sf::Color::Black);
	this->Lvl.setString("level passed");
	this->Lvl.setCharacterSize(20);
	this->Words.setFont(this->regularFont);
	this->Words.setPosition(700.f, 180.f);
	this->Words.setFillColor(sf::Color::Black);
	this->Words.setString("words solved");
	this->Words.setCharacterSize(20);
	this->Letters.setFont(this->regularFont);
	this->Letters.setPosition(1000.f, 180.f);
	this->Letters.setFillColor(sf::Color::Black);
	this->Letters.setString("letters solved");
	this->Letters.setCharacterSize(20);
	this->BestPlayer.setFont(this->regularFont);
	this->BestPlayer.setPosition(150.f, 280.f);
	this->BestPlayer.setFillColor(sf::Color::Black);
	this->BestPlayer.setString("Best player:");
	this->BestPlayer.setCharacterSize(25);
}
//Method that shows current player & best player statistics
void Statistics::fillStats()
{
	Player temp = database.getPlayer(playerID);
	this->currentNick.setFont(this->regularFont);
	this->currentNick.setPosition(170.f, 220.f);
	this->currentNick.setFillColor(sf::Color::Black);
	this->currentNick.setString(temp.getNick());
	this->currentNick.setCharacterSize(23);
	this->currentLvl.setFont(this->regularFont);
	this->currentLvl.setPosition(430.f, 220.f);
	this->currentLvl.setFillColor(sf::Color::Black);
	this->currentLvl.setString(std::to_string(temp.getLvl()));
	this->currentLvl.setCharacterSize(23);
	this->currentW.setFont(this->regularFont);
	this->currentW.setPosition(740.f, 220.f);
	this->currentW.setFillColor(sf::Color::Black);
	this->currentW.setString(std::to_string(temp.getWords()));
	this->currentW.setCharacterSize(23);
	this->currentL.setFont(this->regularFont);
	this->currentL.setPosition(1030.f, 220.f);
	this->currentL.setFillColor(sf::Color::Black);
	this->currentL.setString(std::to_string(temp.getLetters()));
	this->currentL.setCharacterSize(23);
	bool isTrue = false;
	int ifbetter;
	database.doesBetterExist(playerID, isTrue, ifbetter);
	if (isTrue == true) {
		isCurrentBest = false;
		temp = database.getPlayer(ifbetter);
		this->BestNick.setFont(this->regularFont);
		this->BestNick.setPosition(170.f, 330.f);
		this->BestNick.setFillColor(sf::Color::Black);
		this->BestNick.setString(temp.getNick());
		this->BestNick.setCharacterSize(23);
		this->BestLvl.setFont(this->regularFont);
		this->BestLvl.setPosition(430.f, 330.f);
		this->BestLvl.setFillColor(sf::Color::Black);
		this->BestLvl.setString(std::to_string(temp.getLvl()));
		this->BestLvl.setCharacterSize(23);
		this->BestW.setFont(this->regularFont);
		this->BestW.setPosition(740.f, 330.f);
		this->BestW.setFillColor(sf::Color::Black);
		this->BestW.setString(std::to_string(temp.getWords()));
		this->BestW.setCharacterSize(23);
		this->BestL.setFont(this->regularFont);
		this->BestL.setPosition(1030.f, 330.f);
		this->BestL.setFillColor(sf::Color::Black);
		this->BestL.setString(std::to_string(temp.getLetters()));
		this->BestL.setCharacterSize(23);
	}
	else {
		isCurrentBest = true;
		this->YouBest.setFont(this->regularFont);
		this->YouBest.setPosition(170.f, 330.f);
		this->YouBest.setFillColor(sf::Color::Black);
		this->YouBest.setString("You are the best player! Congratulation!");
		this->YouBest.setCharacterSize(23);
	}
}
//Updates Mouse Position on screen, takes reference to window
void Statistics::updateMousePosWindow(sf::RenderWindow* window)
{
	this->mousePos = sf::Mouse::getPosition(*window);
}
