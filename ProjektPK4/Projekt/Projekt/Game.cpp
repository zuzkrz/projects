#include "pch.h"
#include "Game.h"

//Method that creates Player and Quote databases.
void Game::initDatabase()
{
	this->Playerdata.createDatabase();
	this->Quotedata.createDatabase();
}
//Initializing Panels
void Game::initPanels()
{
	this->login = new Login(Playerdata);
	this->menu = new Main();
	this->stats = new Statistics(this->Playerdata, this->currentPlayerID);
	this->help = new Help();
	this->play = new Play(this->Quotedata);
}
//Initializing Variables
void Game::initVariables()
{
	this->window = nullptr;
}
//Initializing window
void Game::initWindow()
{
	this->videoMode = sf::VideoMode(1500, 800);
	this->window = new sf::RenderWindow(this->videoMode, "Crypto", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}
//Method that returns random level from QuoteDatabase
void Game::randomLevel()
{
	this->currentQuote = std::rand() % this->Quotedata.getSize();
}
//Initializing gamestate to LOGIN
void Game::initEnum()
{
	this->state = GameState::LOGIN;
}
//Updates Mouse Position on screen, takes reference to window
void Game::updateMousePos()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}
//Initializing Icon
void Game::initIcon()
{
	if (!icon.loadFromFile("png/icon.png"))
	{
		std::cerr << "Couldn't load icon!\n";
	}
	else {
		this->window->setIcon(100, 100, icon.getPixelsPtr());
	}
}

Game::Game()
{
	this->initEnum();
	this->initDatabase();
	this->initPanels();
	this->initVariables();
	this->initWindow();
	this->initIcon();
}

Game::~Game()
{
	delete this->window;
	delete this->login;
	delete this->menu;
	delete this->stats;
	delete this->help;
	delete this->play;
}
//Method that checks if game is running
bool Game::running()
{
	return this->window->isOpen();
}
//Method that checks if there are any actions preform in a window.
void Game::pollEvents()
{
	if (this->state == GameState::LOGIN) {
		this->login->pollEvents(this->window);
		if (this->login->returnGameState() == GameState::MAIN) {
			menu->updateDatabase(this->Playerdata);
			menu->currentPlayerID(this->currentPlayerID);
			this->state = GameState::MAIN;
			this->login->setState(GameState::LOGIN);
		}
	}
	if (this->state == GameState::MAIN) {
		this->menu->pollEvents(this->window);
		if (this->menu->returnGameState() == GameState::STATISTICS) {
			this->state = GameState::STATISTICS;
			stats->updateDatabase(this->Playerdata);
			stats->currentPlayerID(this->currentPlayerID);
			this->menu->setState(GameState::MAIN);
		}
		if (this->menu->returnGameState() == GameState::HELP) {
			this->state = GameState::HELP;
			this->menu->setState(GameState::MAIN);
		}
		if (this->menu->returnGameState() == GameState::PLAY) {
			this->state = GameState::PLAY;
			this->randomLevel();
			play->currentPlayerID(currentQuote);
			this->menu->setState(GameState::MAIN);
		}
	}
	if (this->state == GameState::STATISTICS) {
		this->stats->pollEvents(this->window);
		if (this->stats->returnGameState() == GameState::MAIN) {
			this->state = GameState::MAIN;
			this->stats->setState(GameState::STATISTICS);
		}
	}
	if (this->state == GameState::HELP) {
		this->help->pollEvents(this->window);
		if (this->help->returnGameState() == GameState::MAIN) {
			this->state = GameState::MAIN;
			this->help->setState(GameState::HELP);
		}
	}
	if (this->state == GameState::PLAY) {
		this->play->pollEvents(this->window);
		if (this->play->returnGameState() == GameState::MAIN) {
			if (this->play->isWon() == true) {
				this->Playerdata.updatePlayer(this->currentPlayerID, this->Quotedata.getWords(this->currentQuote), this->Quotedata.getLetters(this->currentQuote));
			}
			this->state = GameState::MAIN;
			this->play->setState(GameState::PLAY);
		}
	}
}
//Method that updates object in window
void Game::update()
{
	this->updateMousePos();
	this->pollEvents();
	if (this->state == GameState::LOGIN) {
		this->login->update(this->window);
		this->currentPlayerID = login->currentPlayerID(0);
		this->login->updateDatabase(Playerdata);
	}
	if (this->state == GameState::MAIN) {
		this->menu->update(this->window);
	}
	if (this->state == GameState::STATISTICS) {
		this->stats->update(this->window);
	}
	if (this->state == GameState::HELP) {
		this->help->update(this->window);
	}
	if (this->state == GameState::PLAY) {
		this->play->update(this->window);
	}
}
//Method that renders window
void Game::render()
{
	this->window->clear();
	if (this->state == GameState::LOGIN) {
		this->login->draw(this->window);
	}
	if (this->state == GameState::MAIN) {
		this->menu->draw(this->window);
	}
	if (this->state == GameState::STATISTICS) {
		this->stats->draw(this->window);
	}
	if (this->state == GameState::HELP) {
		this->help->draw(this->window);
	}
	if (this->state == GameState::PLAY) {
		this->play->draw(this->window);
	}

	this->window->display();
}
