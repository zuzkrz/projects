#include "pch.h"
#include "MainMenu.h"

//Initializing gamestate to MAIN
void Main::initEnum()
{
	this->state = GameState::MAIN;
}
//Initializing Sprites
void Main::initSprite()
{
	this->LoginBackgroundSprite.setTexture(this->LoginBackgroundTexture);
	this->helpSprite.setTexture(this->helpTexture);
	this->helpSprite.setPosition(1400.f,50.f);
}
//Initializing Textures
void Main::initTexture()
{
	if (!this->LoginBackgroundTexture.loadFromFile("png/loginbckgrnd.png")) {
		std::cerr << "Couldn't load LoginBackground!\n";
	}
	if (!this->helpTexture.loadFromFile("png/help.png")) {
		std::cerr << "Couldn't load helpTexture!\n";
	}
	if (!this->helpColorTexture.loadFromFile("png/help2.png")) {
		std::cerr << "Couldn't load helpTexture2!\n";
	}
}
//Initializing Variables
void Main::initVariables() {
	std::string base = "abcdefghijklmnopqrstuwxyz";
	for (int i = 0; i < 250; i++) {
		int r = std::rand() % 25;
		int o = std::rand() % 1490 + 1;
		sf::Text temp(base[r], this->regularFont, 25U);
		temp.setFillColor(sf::Color(0, 0, 0, 60));
		float t = std::rand() % 790;
		temp.setPosition(1.f * o, t);
		this->animetedLetters.push_back(temp);
	}
}
//Initializing Buttons
void Main::initButton()
{
	this->PlayButton.setPosition(600.f, 400.f);
	this->PlayButton.setSize(sf::Vector2f(300.f, 70.f));
	this->PlayButton.setFillColor(sf::Color(138, 138, 138, 100));
	this->PlayButton.setOutlineColor(sf::Color::Black);
	this->PlayButton.setOutlineThickness(1.f);
	this->exitButton.setPosition(600.f, 580.f);
	this->exitButton.setSize(sf::Vector2f(300.f, 70.f));
	this->exitButton.setFillColor(sf::Color(138, 138, 138, 100));
	this->exitButton.setOutlineColor(sf::Color::Black);
	this->exitButton.setOutlineThickness(1.f);
	this->statisticsButton.setPosition(600.f, 490.f);
	this->statisticsButton.setSize(sf::Vector2f(300.f, 70.f));
	this->statisticsButton.setFillColor(sf::Color(138, 138, 138, 100));
	this->statisticsButton.setOutlineColor(sf::Color::Black);
	this->statisticsButton.setOutlineThickness(1.f);
}
//Initializing Font
void Main::initFont()
{
	if (!this->titleFont.loadFromFile("font/cryptofont.otf")) {
		std::cerr << "Couldn't load cryptofont!\n";
	}
	if (!this->regularFont.loadFromFile("font/regularfont.ttf")) {
		std::cerr << "Couldn't load cryptofont!\n";
	}
}
//Initializing Text
void Main::initText()
{
	this->TitleText.setFont(this->titleFont);
	this->TitleText.setPosition(564.f, 0.f);
	this->TitleText.setFillColor(sf::Color::Black);
	this->TitleText.setString("CRYPTO");
	this->TitleText.setCharacterSize(150);
	this->welcomeText.setFont(this->regularFont);
	this->welcomeText.setPosition(564.f, 200.f);
	this->welcomeText.setFillColor(sf::Color::Black);
	this->welcomeText.setString("Hello! ");
	this->welcomeText.setCharacterSize(30);
	this->exitButtonText.setFont(this->regularFont);
	this->exitButtonText.setPosition(720.f, 595.f);
	this->exitButtonText.setFillColor(sf::Color::Black);
	this->exitButtonText.setString("EXIT");
	this->playButtonText.setFont(this->regularFont);
	this->playButtonText.setPosition(720.f, 415.f);
	this->playButtonText.setFillColor(sf::Color::Black);
	this->playButtonText.setString("PLAY");
	this->statisticsButtonText.setFont(this->regularFont);
	this->statisticsButtonText.setPosition(680.f, 505.f);
	this->statisticsButtonText.setFillColor(sf::Color::Black);
	this->statisticsButtonText.setString("STATISTICS");
}
//Updates Mouse Position on screen, takes reference to window
void Main::updateMousePosWindow(sf::RenderWindow* window)
{
	this->mousePos = sf::Mouse::getPosition(*window);
}

Main::Main()
{
	this->initButton();
	this->initEnum();
	this->initFont();
	this->initVariables();
	this->initTexture();
	this->initText();
	this->initSprite();
}

Main::~Main()
{
}
//Method that draws object in window
void Main::draw(sf::RenderWindow*& window)
{
	window->draw(this->LoginBackgroundSprite);
	for (auto& i : this->animetedLetters) {
		window->draw(i);
		float r = std::rand()%2 + 1;
		i.setPosition(sf::Vector2f(i.getPosition().x, i.getPosition().y + r));
		if (i.getPosition().y >= window->getSize().y) {
			i.setPosition(sf::Vector2f(i.getPosition().x, -20.f));
		}
	}
	window->draw(this->TitleText);
	window->draw(this->welcomeText);
	window->draw(this->PlayButton);
	window->draw(this->playButtonText);
	window->draw(this->exitButton);
	window->draw(this->exitButtonText);
	window->draw(this->statisticsButton);
	window->draw(this->statisticsButtonText);
	window->draw(this->helpSprite);
}
//Method that updates object in window
void Main::update(sf::RenderWindow* window)
{
	this->updateMousePosWindow(window);
	if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 400.f && mousePos.y <= 470.f) {
		this->PlayButton.setOutlineThickness(2.f);
		this->PlayButton.setFillColor(sf::Color(138, 138, 138, 150));
	}
	else {
		this->PlayButton.setOutlineThickness(1.f);
		this->PlayButton.setFillColor(sf::Color(138, 138, 138, 100));
	}
	if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 580.f && mousePos.y <= 650.f) {
		this->exitButton.setOutlineThickness(2.f);
		this->exitButton.setFillColor(sf::Color(138, 138, 138, 150));
	}
	else {
		this->exitButton.setOutlineThickness(1.f);
		this->exitButton.setFillColor(sf::Color(138, 138, 138, 100));
	}
	if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 490.f && mousePos.y <= 560.f) {
		this->statisticsButton.setOutlineThickness(2.f);
		this->statisticsButton.setFillColor(sf::Color(138, 138, 138, 150));
	}
	else {
		this->statisticsButton.setOutlineThickness(1.f);
		this->statisticsButton.setFillColor(sf::Color(138, 138, 138, 100));
	}
	if (mousePos.x >= 1400.f && mousePos.x <= 1440.f && mousePos.y >= 50.f && mousePos.y <= 90.f) {
		this->helpSprite.setTexture(this->helpColorTexture);
	}
	else {
		this->helpSprite.setTexture(this->helpTexture);
	}
}
//Method that checks if there are any actions preform in a window.
void Main::pollEvents(sf::RenderWindow*& window)
{
	while (window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 580.f && mousePos.y <= 650.f) {
				window->close();
			}
			if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 490.f && mousePos.y <= 560.f) {
				this->state = GameState::STATISTICS;
			}
			if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 400.f && mousePos.y <= 470.f) {
				this->state = GameState::PLAY;
			}
			if (mousePos.x >= 1400.f && mousePos.x <= 1440.f && mousePos.y >= 50.f && mousePos.y <= 90.f) {
				this->state = GameState::HELP;
			}
			break;
		}
	}
}
//Method that returns gamestate
GameState Main::returnGameState()
{
	return this->state;
}
//Method that sets gamestate
void Main::setState(GameState sentState)
{
	this->state = sentState;
}
//Method that updates current player ID to value sent
int Main::currentPlayerID(int id)
{
	this->currentID = id;
	this->welcomeText.setString("Hello! " + database.getNick(currentID));
	return 0;
}
//Method that copies data from passed database to local database
void Main::updateDatabase(PlayerDatabase& data)
{
	this->database = data;
}
//Method that does nothing in this class
bool Main::isWon()
{
	return false;
}
