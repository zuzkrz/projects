#include "pch.h"
#include "Login.h"

//Initializing gamestate to LOGIN
void Login::initEnum()
{
	this->state = GameState::LOGIN;
}
//Initializing Sprites
void Login::initSprite()
{
	this->LoginBackgroundSprite.setTexture(this->LoginBackgroundTexture);
}
//Initializing Textures
void Login::initTexture()
{
	if (!this->LoginBackgroundTexture.loadFromFile("png/loginbckgrnd.png")) {
		std::cerr << "Couldn't load LoginBackground!\n";
	}
}
//Initializing TextBox
void Login::initTextBox()
{
	this->TextBox.setPosition(600.f, 250.f);
	this->TextBox.setSize(sf::Vector2f(300.f, 55.f));
	this->TextBox.setFillColor(sf::Color::White);
	this->TextBox.setOutlineColor(sf::Color::Black);
}
//Initializing Variables
void Login::initVariables()
{
	this->isNewClicked = false;
	this->newNick = "";
	this->isLoginValid = false;
	this->playerID = 0;
}
//Updates Mouse Position on screen, takes reference to window
void Login::updateMousePosWindow(sf::RenderWindow* window)
{
	this->mousePos = sf::Mouse::getPosition(*window);
}
//Initializing Text
void Login::initText()
{
	this->TitleText.setFont(this->titleFont);
	this->TitleText.setPosition(564.f, 0.f);
	this->TitleText.setFillColor(sf::Color::Black);
	this->TitleText.setString("CRYPTO");
	this->TitleText.setCharacterSize(150);
	this->Nick.setFont(this->regularFont);
	this->Nick.setPosition(610.f, 255.f);
	this->Nick.setFillColor(sf::Color::Black);
	this->welcomeText.setFont(this->regularFont);
	this->welcomeText.setPosition(453.f, 200.f);
	this->welcomeText.setFillColor(sf::Color::Black);
	this->welcomeText.setString("Hello! Please login - if you are new select a checkbox!");
	this->welcomeText.setCharacterSize(25);
	this->exitButtonText.setFont(this->regularFont);
	this->exitButtonText.setPosition(720.f, 555.f);
	this->exitButtonText.setFillColor(sf::Color::Black);
	this->exitButtonText.setString("EXIT");
	this->loginButtonText.setFont(this->regularFont);
	this->loginButtonText.setPosition(710.f, 465.f);
	this->loginButtonText.setFillColor(sf::Color::Black);
	this->loginButtonText.setString("LOGIN");
	this->ValidationInfo.setFont(this->regularFont);
	this->ValidationInfo.setPosition(575.f, 305.f);
	this->ValidationInfo.setFillColor(sf::Color::Black);
	this->ValidationInfo.setString("Range or characters: 3-10. Use only letters and numbers!");
	this->ValidationInfo.setCharacterSize(15);
	this->checkBoxText.setFont(this->regularFont);
	this->checkBoxText.setPosition(645.f, 333.f);
	this->checkBoxText.setFillColor(sf::Color::Black);
	this->checkBoxText.setString("Check if you are new player");
	this->checkBoxText.setCharacterSize(19);
	this->tick.setFont(this->regularFont);
	this->tick.setPosition(625.f, 334.f);
	this->tick.setString("");
	this->tick.setFillColor(sf::Color::Black);
	this->tick.setCharacterSize(17);
	this->errorLoginText.setFont(this->regularFont);
	this->errorLoginText.setPosition(600.f, 370.f);
	this->errorLoginText.setFillColor(sf::Color::Red);
	this->errorLoginText.setString("");
	this->errorLoginText.setCharacterSize(20);
}
//Initializing Font
void Login::initFont()
{
	if (!this->titleFont.loadFromFile("font/cryptofont.otf")) {
		std::cerr << "Couldn't load cryptofont!\n";
	}
	if (!this->regularFont.loadFromFile("font/regularfont.ttf")) {
		std::cerr << "Couldn't load cryptofont!\n";
	}
}
//Initializing Buttons
void Login::initButton()
{
	this->exitButton.setPosition(600.f, 540.f);
	this->exitButton.setSize(sf::Vector2f(300.f, 70.f));
	this->exitButton.setFillColor(sf::Color(138, 138, 138, 100));
	this->exitButton.setOutlineColor(sf::Color::Black);
	this->exitButton.setOutlineThickness(1.f);
	this->checkBox.setPosition(620.f, 335.f);
	this->checkBox.setSize(sf::Vector2f(20.f, 20.f));
	this->checkBox.setFillColor(sf::Color(138, 138, 138, 100));
	this->checkBox.setOutlineColor(sf::Color::Black);
	this->checkBox.setOutlineThickness(1.f);
	this->LoginButton.setPosition(600.f, 450.f);
	this->LoginButton.setSize(sf::Vector2f(300.f, 70.f));
	this->LoginButton.setFillColor(sf::Color(138, 138, 138, 100));
	this->LoginButton.setOutlineColor(sf::Color::Black);
	this->LoginButton.setOutlineThickness(1.f);
}
//Method that checks if nick if correct/valid/aviable
int Login::isNickValid()
{
	std::string temp = this->Nick.getString();
	auto scheme = std::regex("^[A-Za-z0-9]{3,10}$");
	bool test = std::regex_match(temp, scheme);
	if (test == false) {
		return 1;
	}
	if (isNewClicked == false) {
		if (database.doesPlayerExist(temp) == true) {
			this->playerID = database.getID(temp);
			return 2;
		}
		else {
			return 3;
		}
	}
	else {
		if (database.doesPlayerExist(temp) == true) {
			return 4;
		}
		else {
			database.createPlayer(temp);
			this->playerID = database.size() - 1;
			return 5;
		}
	}
}
//Method that return player id in database
int Login::currentPlayerID(int id)
{
	return this->playerID;
}
//Method that updates sent database if new player logged in
void Login::updateDatabase(PlayerDatabase& data)
{
	if (data.size() != database.size()) {
		Player temp = database.getPlayer(database.size()-1);
		data.createPlayer(temp.getNick());
	}
}
//Method that does nothing in this class
bool Login::isWon()
{
	return false;
}

Login::Login(PlayerDatabase& data)
{
	this->database = data;
	this->initEnum();
	this->initTexture();
	this->initSprite();
	this->initVariables();
	this->initFont();
	this->initButton();
	this->initText();
	this->initTextBox();
}

Login::~Login()
{
}
//Method that draws object in window
void Login::draw(sf::RenderWindow*& window)
{
	window->draw(this->LoginBackgroundSprite);
	window->draw(this->TitleText);
	window->draw(this->welcomeText);
	window->draw(this->TextBox);
	window->draw(this->Nick);
	window->draw(this->ValidationInfo);
	window->draw(this->exitButton);
	window->draw(this->exitButtonText);
	window->draw(this->LoginButton);
	window->draw(this->loginButtonText);
	window->draw(this->checkBox);
	window->draw(this->tick);
	window->draw(this->checkBoxText);
	window->draw(this->errorLoginText);
}
//Method that returns gamestate
GameState Login::returnGameState()
{
	return this->state;
}
//Method that sets gamestate
void Login::setState(GameState sentState)
{
	this->state = sentState;
}
//Method that updates object in window
void Login::update(sf::RenderWindow* window) {
	this->updateMousePosWindow(window);
	if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 540.f && mousePos.y <= 610.f) {
		this->exitButton.setOutlineThickness(2.f);
		this->exitButton.setFillColor(sf::Color(138, 138, 138, 150));
	}
	else {
		this->exitButton.setOutlineThickness(1.f);
		this->exitButton.setFillColor(sf::Color(138, 138, 138, 100));
	}
	if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 450.f && mousePos.y <= 520.f) {
		this->LoginButton.setOutlineThickness(2.f);
		this->LoginButton.setFillColor(sf::Color(138, 138, 138, 150));
	}
	else {
		this->LoginButton.setOutlineThickness(1.f);
		this->LoginButton.setFillColor(sf::Color(138, 138, 138, 100));
	}
	if (mousePos.x >= 620.f && mousePos.x <= 640.f && mousePos.y >= 335.f && mousePos.y <= 355.f && this->isLoginValid == false) {
		this->checkBox.setOutlineThickness(2.f);
		this->checkBox.setFillColor(sf::Color(138, 138, 138, 150));
	}
	else {
		this->checkBox.setOutlineThickness(1.f);
		this->checkBox.setFillColor(sf::Color(138, 138, 138, 100));
	}
	if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 250.f && mousePos.y <= 305.f && this->isLoginValid == false) {
		this->TextBox.setOutlineThickness(1.f);
	}
	else if (!this->isTextBoxClicked) {
		this->TextBox.setOutlineThickness(0.f);
	}
};
//Method that checks if there are any actions preform in a window.
void Login::pollEvents(sf::RenderWindow*& window) {
	while (window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::MouseButtonPressed:
			if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 540.f && mousePos.y <= 610.f) {
				window->close();
			} //exit button
			if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 450.f && mousePos.y <= 520.f && this->isLoginValid == true) {
				this->state = GameState::MAIN;
			}
			if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 450.f && mousePos.y <= 520.f && this->isLoginValid == false) {
				int returnIsNickValid = isNickValid();
				if (returnIsNickValid == 1) {
					this->errorLoginText.setString("Invalid characters or number of them!");
				}
				else if (returnIsNickValid == 2) {
					this->errorLoginText.setFillColor(sf::Color::Black);
					this->errorLoginText.setString("Logged in correctly! Press enter");
					this->loginButtonText.setString("ENTER");
					this->isLoginValid = true;
				}
				else if (returnIsNickValid == 3) {
					this->errorLoginText.setString("There is no such player! Try again");
				}
				else if (returnIsNickValid == 4) {
					this->errorLoginText.setString("Nickname is already taken! Try again");
				}
				else if (returnIsNickValid == 5) {
					this->errorLoginText.setFillColor(sf::Color::Black);
					this->errorLoginText.setString("Registered correctly! Press enter");
					this->loginButtonText.setString("ENTER");
					this->isLoginValid = true;
				}
			}
			if (mousePos.x >= 620.f && mousePos.x <= 640.f && mousePos.y >= 335.f && mousePos.y <= 355.f) {
				if (this->tick.getString() == "") {
					this->tick.setString("X");
					this->isNewClicked = true;

				}
				else {
					this->tick.setString("");
					this->isNewClicked = false;
				}
			}
			if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 250.f && mousePos.y <= 305.f) {
				this->isTextBoxClicked = true;
			}
			else {
				this->isTextBoxClicked = false;
			}
			break;
		case sf::Event::TextEntered:
			if (this->isTextBoxClicked == true && this->isLoginValid == false) {
				if (this->ev.text.unicode == 8) {
					if (this->newNick.size() != 0) {
						this->newNick.pop_back();
						this->Nick.setString(this->newNick);
					}
				}
				else {
					if (this->newNick.size() < 12) {
						this->newNick.push_back((char)this->ev.text.unicode);
						this->Nick.setString(this->newNick);
					}
				}
			}
			break;
		}
	}
};

