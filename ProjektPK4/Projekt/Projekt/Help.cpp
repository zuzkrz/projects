#include "pch.h"
#include "Help.h"

//Updates Mouse Position on screen, takes reference to window
void Help::updateMousePosWindow(sf::RenderWindow* window)
{
	this->mousePos = sf::Mouse::getPosition(*window);
}
//Initializing Sprites
void Help::initSprite()
{
	this->BackgroundSprite.setTexture(this->BackgroundTexture);
	this->helpinfo1Sprite.setTexture(this->helpinfo1);
	this->helpinfo1Sprite.setPosition(163.f, 200.f);
	this->helpinfo2Sprite.setTexture(this->helpinfo2);
	this->helpinfo2Sprite.setPosition(575.f, 200.f);
	this->helpinfo3Sprite.setTexture(this->helpinfo3);
	this->helpinfo3Sprite.setPosition(985.f, 200.f);
}
//Initializing Textures
void Help::initTexture()
{
	if (!this->BackgroundTexture.loadFromFile("png/statsbckgrnd.png")) {
		std::cerr << "Couldn't load LoginBackground!\n";
	}
	if (!this->helpinfo1.loadFromFile("png/help1.png")) {
		std::cerr << "Couldn't load help1!\n";
	}
	if (!this->helpinfo2.loadFromFile("png/help22.png")) {
		std::cerr << "Couldn't load help22!\n";
	}
	if (!this->helpinfo3.loadFromFile("png/help3.png")) {
		std::cerr << "Couldn't load help3!\n";
	}
}
//Initializing Buttons
void Help::initButton()
{
	this->backButton.setPosition(600.f, 585.f);
	this->backButton.setSize(sf::Vector2f(300.f, 70.f));
	this->backButton.setFillColor(sf::Color(138, 138, 138, 100));
	this->backButton.setOutlineColor(sf::Color::Black);
	this->backButton.setOutlineThickness(1.f);
}
//Initializing Font
void Help::initFont()
{
	if (!this->titleFont.loadFromFile("font/cryptofont.otf")) {
		std::cerr << "Couldn't load cryptofont!\n";
	}
	if (!this->regularFont.loadFromFile("font/regularfont.ttf")) {
		std::cerr << "Couldn't load cryptofont!\n";
	}
}
//Initializing Text
void Help::initText()
{
	this->TitleText.setFont(this->titleFont);
	this->TitleText.setPosition(565.f, 50.f);
	this->TitleText.setFillColor(sf::Color::Black);
	this->TitleText.setString("HOW TO PLAY");
	this->TitleText.setCharacterSize(80);
	this->BackButtonText.setFont(this->regularFont);
	this->BackButtonText.setPosition(680.f, 600.f);
	this->BackButtonText.setFillColor(sf::Color::Black);
	this->BackButtonText.setString("GO BACK");
}
//Initializing gamestate to HELP
void Help::initEnum()
{
	this->state = GameState::HELP;
}

Help::Help()
{
	this->initEnum();
	this->initTexture();
	this->initSprite();
	this->initFont();
	this->initText();
	this->initButton();
}

Help::~Help()
{
}
//Method that draws object in window
void Help::draw(sf::RenderWindow*& window)
{
	window->draw(this->BackgroundSprite);
	window->draw(this->backButton);
	window->draw(this->BackButtonText);
	window->draw(this->TitleText);
	window->draw(this->helpinfo1Sprite);
	window->draw(this->helpinfo2Sprite);
	window->draw(this->helpinfo3Sprite);
}
//Method that updates object in window
void Help::update(sf::RenderWindow* window)
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
void Help::pollEvents(sf::RenderWindow*& window)
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
GameState Help::returnGameState()
{
	return this->state;
}
//Method that sets gamestate
void Help::setState(GameState sentState)
{
	this->state = sentState;
}
//Method that does nothing in this class
int Help::currentPlayerID(int i)
{
	return 0;
}
//Method that does nothing in this class
void Help::updateDatabase(PlayerDatabase& data)
{
}
//Method that does nothing in this class
bool Help::isWon()
{
	return false;
}
