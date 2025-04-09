#include "pch.h"
import Lock;
#include "Play.h"

//Updates Mouse Position on screen, takes reference to window
void Play::updateMousePosWindow(sf::RenderWindow* window)
{
	this->mousePos = sf::Mouse::getPosition(*window);
}
//Initializing Textures
void Play::initTexture()
{
	if (!this->BackgroundTexture.loadFromFile("png/playbckgrnd.png")) {
		std::cerr << "Couldn't load PlayBackground!\n";
	}
	if (!this->pauseTexture.loadFromFile("png/pause.png")) {
		std::cerr << "Couldn't load pause!\n";
	}
	if (!this->pauseOnTexture.loadFromFile("png/pauseClicked.png")) {
		std::cerr << "Couldn't load life!\n";
	}
	if (!this->heartTexture.loadFromFile("png/life.png")) {
		std::cerr << "Couldn't load life!\n";
	}
	if (!this->heartLostTexture.loadFromFile("png/lifeLost.png")) {
		std::cerr << "Couldn't load lifeLost!\n";
	}
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
//Initializing Sprites
void Play::initSprite()
{
	this->BackgroundSprite.setTexture(this->BackgroundTexture);
	this->pauseSprite.setTexture(this->pauseTexture);
	this->pauseSprite.setPosition(1430.f, 60.f);
	this->life1.setTexture(this->heartTexture);
	this->life1.setPosition(692.f, 5.f);
	this->life2.setTexture(this->heartTexture);
	this->life2.setPosition(732.f, 5.f);
	this->life3.setTexture(this->heartTexture);
	this->life3.setPosition(772.f, 5.f);
}
//Initializing gamestate to PLAY
void Play::initEnum()
{
	this->state = GameState::PLAY;
}
//Initializing objects that are shown when 'pause' is clicked
void Play::initPause()
{
	this->pauseBlock.setPosition(300.f, 100.f);
	this->pauseBlock.setSize(sf::Vector2f(900.f, 600.f));
	this->pauseBlock.setFillColor(sf::Color(209, 165, 134, 70));
	this->pauseBlock.setOutlineColor(sf::Color::Black);
	this->pauseBlock.setOutlineThickness(2.f);
	this->pauseBack.setPosition(400.f, 500.f);
	this->pauseBack.setSize(sf::Vector2f(300.f, 100.f));
	this->pauseBack.setFillColor(sf::Color(138, 138, 138, 100));
	this->pauseBack.setOutlineColor(sf::Color::Black);
	this->pauseBack.setOutlineThickness(1.f);
	this->pauseMain.setPosition(800.f, 500.f);
	this->pauseMain.setSize(sf::Vector2f(300.f, 100.f));
	this->pauseMain.setFillColor(sf::Color(138, 138, 138, 100));
	this->pauseMain.setOutlineColor(sf::Color::Black);
	this->pauseMain.setOutlineThickness(1.f);
	this->pauseText.setFont(this->regularFont);
	this->pauseText.setPosition(sf::Vector2f(430.f, 200.f));
	this->pauseText.setString("GAME PAUSED");
	this->pauseText.setFillColor(sf::Color::Black);
	this->pauseText.setCharacterSize(100);
	this->pauseBackText.setFont(this->regularFont);
	this->pauseBackText.setPosition(sf::Vector2f(465.f, 520.f));
	this->pauseBackText.setString("UNPAUSE");
	this->pauseBackText.setFillColor(sf::Color::Black);
	this->pauseBackText.setCharacterSize(40);
	this->pauseMainText.setFont(this->regularFont);
	this->pauseMainText.setPosition(sf::Vector2f(908.f, 520.f));
	this->pauseMainText.setString("MAIN");
	this->pauseMainText.setFillColor(sf::Color::Black);
	this->pauseMainText.setCharacterSize(40);
}
//Clearing vectors, assigning variables their 'default' value. Preparing for next level. 
void Play::clean()
{
	this->difficulty = 0;
	this->vecLetters.clear();
	this->differentLetters.clear();
	this->howManyLetters.clear();
	this->assignedNumber.clear();
	this->LockPos.clear();
	this->LockPosForvecLetter.clear();
	this->locks.clear();
	this->isPaused = false;
	this->isGameOver = false;
	this->life = 3;
	this->currentKey = ' ';
	this->isPressedKey = false;
	this->life1.setTexture(this->heartTexture);
	this->life2.setTexture(this->heartTexture);
	this->life3.setTexture(this->heartTexture);
}
//Initializing Font
void Play::initFont()
{
	if (!this->regularFont.loadFromFile("font/regularfont.ttf")) {
		std::cerr << "Couldn't load cryptofont!\n";
	}
}
//Initializing Keyboard
void Play::initKeyboard()
{
	std::vector<char> letters = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };
	float positionX2 = 440;
	float positionX3 = 510;
	int row1 = 9;
	int row2 = 10;
	float y = 650;
	bool temp = true;
	bool temp1 = true;
	float x = 405;
	for (auto i : letters) {
		keyboard.push_back(Keyboard(x, y, i));
		x = x + 70;
		if (row1 != 0) {
			row1--;
		}
		else if (row1 == 0 && temp1 == true){
			x = positionX2;
			y = y + 50;
			temp1 = false;
		}
		if (row2 != 0 && row1 == 0) {
			row2--;
		}
		else if (row2 == 0 && row1 == 0 && temp == true){
			x = positionX3;
			y = y + 50;
			temp = false;
		}
	}
}
//Method that every time makes different set of numbers assign to specific letters.
void Play::assignNumber()
{
	std::vector<char> unsorted = currentQuote.getQuote();
	std::vector<bool> tempISDONE = currentQuote.isDone();
	std::vector<char> sorted = this->currentQuote.getSortedQuote();
	std::vector<char> letter;
	std::vector<int> occurence, NumbersToRandomize, vecOfRandom;


	bool endCheck = true;
	while (endCheck) {
		if (sorted[sorted.size() - 1] == ' ') {
			sorted.pop_back();
		}
		else {
			endCheck = false;
		}
	}
	
	letter.push_back(sorted[0]);
	occurence.push_back(1);
	int tempIte = 0;
	char temp2;
	for (int i = 1; i < sorted.size(); i++) {
		if (letter[tempIte] != sorted[i]) {
			letter.push_back(sorted[i]);
			occurence.push_back(1);
			tempIte++;
		}
		else {
			occurence[tempIte] = occurence[tempIte] + 1;
		}
	}

	for (int i = 1; i < 34; i++) {
		NumbersToRandomize.push_back(i);
	}
	for (auto i: letter) {
		int randomizer = std::rand()%NumbersToRandomize.size();
		vecOfRandom.push_back(NumbersToRandomize[randomizer]);
		NumbersToRandomize[randomizer] = NumbersToRandomize[NumbersToRandomize.size() - 1];
		NumbersToRandomize.pop_back();
	}
	
	for (int i = 0; i < unsorted.size(); i++) {
		if (unsorted[i] == ' ') {}
		else {
			if (tempISDONE[i] == true) {
				for (int j = 0; j < letter.size(); j++) {
					if (letter[j] == unsorted[i]) {
						occurence[j] = occurence[j] - 1;
					}
				}
			}
		}
	}
	this->assignedNumber = vecOfRandom;
	this->differentLetters = letter;
	this->howManyLetters = occurence;
}
//Initializing Quote. Run every time, when a new game is being played or a game is replayed.
void Play::initQuote()
{
	if (difficulty != 0) {
		prepareLockPos();
	}
	assignNumber();
	initLetters();
	if (difficulty != 0) {
		updateTexture();
	}
}
//Method that creates and position each letter
void Play::initLetters()
{
	int Iter = 0;
	float x = 50.f;
	float y = 150.f;
	std::vector<char> tempQuote = currentQuote.getQuote();
	std::vector<bool> tempIsDone = currentQuote.isDone();
	for (int i = 0; i < tempQuote.size(); i++) {
		int tempAssigned = 0;
		for (int j = 0; j < differentLetters.size(); j++) {
			if (tempQuote[i] == differentLetters[j]) {
				tempAssigned = assignedNumber[j];
			}
		}
		if (tempQuote[i] != ' ') {
			if (difficulty == 1 || difficulty == 2) {
				if (i == LockPos[Iter]) {
					vecLetters.push_back(Letter(x, y, tempQuote[i], tempIsDone[i], tempAssigned, true, this->difficulty));
					Iter++;
					LockPosForvecLetter.push_back(vecLetters.size() - 1);
					sf::Sprite tempSprite;
					tempSprite.setPosition(x, y);
					std::shared_ptr<sf::Sprite> temp = std::make_shared<sf::Sprite>(tempSprite);
					locks.push_back(temp);
				}
				else {
					vecLetters.push_back(Letter(x, y, tempQuote[i], tempIsDone[i], tempAssigned));

				}
			}
			else if (difficulty == 0) {
				vecLetters.push_back(Letter(x, y, tempQuote[i], tempIsDone[i], tempAssigned));
			}
			x =x + 35.f;
		}
		else {
			x =x + 30.f;
			bool nextBlank = false;
			int currenti = i+1;
			int temphowMany = 0;
			while (!nextBlank && currenti < tempQuote.size()) {
				if (tempQuote[currenti] != ' ') {
					temphowMany++;
				}
				else {
					nextBlank = true;
				}
				currenti++;
			}
			if (x + temphowMany * 35.f - 5.f > 1450.f) {
				x = 50.f;
				y = y + 90.f;
			}
		}
	}
}
//Method that updates how many of passed letter remains to guess.
void Play::updateVectors(char passed)
{
	for (int i = 0; i < differentLetters.size(); i++) {
		if (passed == differentLetters[i]) {
			howManyLetters[i] = howManyLetters[i] - 1;

			if (howManyLetters[i] == 0) {
				updateLetter(passed);
			}
		}
	}
}
//Method that makes 'number' under the line disapiere if there is no remaining same letters to guess.
void Play::updateLetter(char passed)
{
	for (auto& i : vecLetters) {
		if (i.getLetter() == passed) {
			i.allDone();
		}
	}
}
//Method that checks if life is lost, if it is lost changes the heart on a screen to 'lost one' and, if all lifes are lost, end game.
void Play::allLivesLost()
{
	if (life == 2) {
		this->life3.setTexture(this->heartLostTexture);
	}
	else if (life == 1) {
		this->life2.setTexture(this->heartLostTexture);
	}
	else if (this->life == 0) {
		this->life1.setTexture(this->heartLostTexture);
		this->isGameOver = true;
	}
}
//Method that checks if game is finished.
void Play::checkIfFinished()
{
	bool tempCheck = true;
	for (auto i : vecLetters) {
		if (i.isDone() == false) {
			tempCheck = false;
		}
	}
	if (tempCheck == true) {
		this->isGameOver = true;
		this->won = true;
	}
}
//Method that prepares locks position
void Play::prepareLockPos()
{
	std::vector<char> tempQuote = this->currentQuote.getQuote();
	std::vector<bool> tempIsDone = this->currentQuote.isDone();
	std::vector<bool> tempIsPossible;

	for (auto i : tempQuote) {
		tempIsPossible.push_back(false);
	}
	if (difficulty == 1) {
		for (int i = 0; i < tempQuote.size(); i++) {
			if (i == 0 && tempIsDone[i + 1] != true && tempIsDone[i] != true) {
				tempIsPossible[i] = true;
			}
			else if (i == tempQuote.size()-1 && tempIsDone[i - 1] != true && tempIsDone[i] != true) {
				tempIsPossible[i] = true;
			}
			else if (tempIsDone[i] == false && i>0) {
				if (tempIsDone[i - 1] == false && tempIsDone[i + 1] == false) {
					tempIsPossible[i] = true;
				}
			}
		}
	}
	else if (difficulty == 2) {
		for (int i = 1; i < tempQuote.size()-1; i++) {
			if (i == 1 && tempQuote[i + 1] != ' ' && tempIsDone[i + 1] != true && tempIsDone[i] != true) {
				tempIsPossible[i] = true;
			}
			else if (i == tempQuote.size() - 2 && tempQuote[i - 1] != ' ' && tempIsDone[i - 1] != true && tempIsDone[i] != true) {
				tempIsPossible[i] = true;
			}
			else if (tempQuote[i - 1] != ' ' && tempIsDone[i - 1] != true && tempQuote[i + 1] != ' ' && tempIsDone[i + 1] != true && tempQuote[i] != ' ' && tempIsDone[i] != true) {
				tempIsPossible[i] = true;
			}
		}
	}
	
	LockPos = Lock::returnLockPosition(tempIsPossible);
}
//Initializing objects that are shown when game ends.
void Play::endGame()
{
	this->endMain.setPosition(600.f, 400.f);
	this->endMain.setSize(sf::Vector2f(300.f, 100.f));
	this->endMain.setFillColor(sf::Color(138, 138, 138, 100));
	this->endMain.setOutlineColor(sf::Color::Black);
	this->endMain.setOutlineThickness(1.f);
	this->endReplay.setPosition(600.f, 550.f);
	this->endReplay.setSize(sf::Vector2f(300.f, 100.f));
	this->endReplay.setFillColor(sf::Color(138, 138, 138, 100));
	this->endReplay.setOutlineColor(sf::Color::Black);
	this->endReplay.setOutlineThickness(1.f);
	this->endGameText.setFont(this->regularFont);
	this->endGameText.setPosition(sf::Vector2f(500.f, 180.f));
	this->endGameText.setFillColor(sf::Color::Black);
	this->endGameText.setCharacterSize(100);
	this->endReplayText.setFont(this->regularFont);
	this->endReplayText.setPosition(sf::Vector2f(685.f, 570.f));
	this->endReplayText.setString("REPLAY");
	this->endReplayText.setFillColor(sf::Color::Black);
	this->endReplayText.setCharacterSize(40);
	this->endMainText.setFont(this->regularFont);
	this->endMainText.setPosition(sf::Vector2f(708.f, 420.f));
	this->endMainText.setString("MAIN");
	this->endMainText.setFillColor(sf::Color::Black);
	this->endMainText.setCharacterSize(40);
}

void Play::checkForUnlocked()
{
	int temp = 44;
	for (auto& i : LockPosForvecLetter) {
		if (vecLetters[i].isLocked() == true) {
			if (this->difficulty == 2) {
				vecLetters[i].updateLockStatus(vecLetters[i-1].isDone(), vecLetters[i+1].isDone());
			}
			else if (this->difficulty == 1) {
				if (i - 1 < 0) {
					vecLetters[i].updateLockStatus(temp, vecLetters[i + 1].isDone());
				}
				else if (i + 1 == vecLetters.size()) {
					vecLetters[i].updateLockStatus(vecLetters[i - 1].isDone(), temp);
				}
				else {
					vecLetters[i].updateLockStatus(vecLetters[i - 1].isDone(), vecLetters[i + 1].isDone());
				}
			}
		}
	}
}

void Play::setCorrectTexture(int no, sf::Sprite& sprite)
{
	if (no == 1) {
		sprite.setTexture(this->lock1);
	}
	else if (no == 2) {
		sprite.setTexture(this->lock2);
	}
	else if (no == 3) {
		sprite.setTexture(this->unlocked1);
	}
	else if (no == 4) {
		sprite.setTexture(this->lock2Right);
	}
	else if (no == 5) {
		sprite.setTexture(this->lock2Left);
	}
	else if (no == 6) {
		sprite.setTexture(this->unlocked2);
	}
}

void Play::updateTexture()
{
		setCorrectTexture(vecLetters[LockPosForvecLetter[2]].correctTexture(), *locks[2]);
		setCorrectTexture(vecLetters[LockPosForvecLetter[0]].correctTexture(), *locks[0]);
		setCorrectTexture(vecLetters[LockPosForvecLetter[1]].correctTexture(), *locks[1]);
}

Play::Play(QuoteDatabase& data)
{
	this->isPaused = false;
	this->isGameOver = false;
	this->life = 3;
	this->database = data;
	this->isPressedKey = false;
	this->initEnum();
	this->initTexture();
	this->initSprite();
	this->initFont();
	this->initKeyboard();
	this->initPause();
	this->endGame();
}

Play::~Play()
{
}
//Method that draws object in window
void Play::draw(sf::RenderWindow*& window)
{
	if (!isGameOver) {
		if (!isPaused) {
			window->draw(this->BackgroundSprite);
			window->draw(this->pauseSprite);
			window->draw(this->life1);
			window->draw(this->life2);
			window->draw(this->life3);
			
			int tempIter = 0;
			for (auto& i : vecLetters) {
				if (i.isLocked() == false) {
					window->draw(i.getButton());
					window->draw(i.getLine());
					std::shared_ptr<sf::Text> letter = i.getText();
					window->draw(*letter);
					std::shared_ptr<sf::Text> letter2 = i.getNum();
					window->draw(*letter2);
				}
				else if (i.isLocked() == true) {
					if (vecLetters[LockPosForvecLetter[tempIter]].isLocked()) {
						window->draw(*locks[0]);
						tempIter++;
					}
					else {
						tempIter++;
					}
					if (vecLetters[LockPosForvecLetter[tempIter]].isLocked()) {
						window->draw(*locks[1]);
						tempIter++;
					}
					else {
						tempIter++;
					}
					if (vecLetters[LockPosForvecLetter[tempIter]].isLocked()) {
						window->draw(*locks[2]);
						tempIter = 0;
					}
					else {
						tempIter = 0;
					}
				}
			}
			for (auto& i : keyboard) {
				window->draw(i.getButton());
				std::shared_ptr<sf::Text> letter = i.getText();
				window->draw(*letter);
			}
		}
		else {
			window->draw(this->BackgroundSprite);
			window->draw(this->pauseBlock);
			window->draw(this->pauseBack);
			window->draw(this->pauseMain);
			window->draw(this->pauseText);
			window->draw(this->pauseMainText);
			window->draw(this->pauseBackText);
		}
	}
	else if (isGameOver) {
		window->draw(this->BackgroundSprite);
		window->draw(this->pauseBlock);
		if (won) {
			this->endGameText.setString("GAME WON!");
		}
		else if (!won) {
			this->endGameText.setString("GAME LOST");
			window->draw(this->endReplay);
			window->draw(this->endReplayText);
		}
		window->draw(this->endGameText);
		window->draw(this->endMain);
		window->draw(this->endMainText);
	}
}
//Method that updates object in window
void Play::update(sf::RenderWindow* window)
{
	this->updateMousePosWindow(window);
	if (this->isPaused == false && this->isGameOver == false) {
		if (mousePos.x >= 1430.f && mousePos.x <= 1480.f && mousePos.y >= 60.f && mousePos.y <= 110.f) {
			this->pauseSprite.setTexture(this->pauseOnTexture);
		}
		else {
			this->pauseSprite.setTexture(this->pauseTexture);
		}
		for (auto& i : vecLetters) {
			i.update(window);
		}
		for (auto& i : keyboard) {
			i.update(window);
		}
	}
	else if (this->isPaused == true) {
		if (mousePos.x >= 400.f && mousePos.x <= 700.f && mousePos.y >= 500.f && mousePos.y <= 600.f) {
			this->pauseBack.setOutlineThickness(2.f);
		}
		else {
			this->pauseBack.setOutlineThickness(1.f);
		}
		if (mousePos.x >= 800.f && mousePos.x <= 1100.f && mousePos.y >= 500.f && mousePos.y <= 600.f) {
			this->pauseMain.setOutlineThickness(2.f);
		}
		else {
			this->pauseMain.setOutlineThickness(1.f);
		}
	}
	else if (this->isGameOver == true) {
		if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 400.f && mousePos.y <= 500.f) {
			this->endMain.setOutlineThickness(2.f);
		}
		else {
			this->endMain.setOutlineThickness(1.f);
		}
		if (this->won == false) {
			if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 550.f && mousePos.y <= 650.f) {
				this->endReplay.setOutlineThickness(2.f);
			}
			else {
				this->endReplay.setOutlineThickness(1.f);
			}
		}
	}
}
//Method that checks if there are any actions preform in a window.
void Play::pollEvents(sf::RenderWindow*& window)
{
	if (this->isGameOver == false) {
		while (window->pollEvent(this->ev)) {
			switch (this->ev.type) {
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::MouseButtonPressed:
				if (this->isPaused == false) {
					if (mousePos.x >= 1430.f && mousePos.x <= 1480.f && mousePos.y >= 60.f && mousePos.y <= 110.f) {
						this->isPaused = true;
					}
					for (auto& i : vecLetters) {
						if (i.isDone() == false && i.isLocked() == false) {
							if (mousePos.x >= i.getX() && mousePos.x <= i.getX() + 30.f && mousePos.y >= i.getY() && mousePos.y <= i.getY() + 60.f) {
								if (currentKey == ' ') {

								}
								else if (i.isCorrect(this->currentKey) == true) {
									this->updateVectors(currentKey);
									this->checkForUnlocked();
									if (difficulty != 0)
									this->updateTexture();
									this->checkIfFinished();
								}
								else if (i.isCorrect(this->currentKey) == false) {
									i.wrongLetter(1);
									this->life--;
									this->allLivesLost();
								}
								currentKey = ' ';
							}
						}
					}

					for (auto& i : keyboard) {
						if (mousePos.x >= i.getX() && mousePos.x <= i.getX() + 60.f && mousePos.y >= i.getY() && mousePos.y <= i.getY() + 40.f) {
							bool temp = true;
							i.updatebool(temp);

							this->isPressedKey = true;
							this->currentKey = i.letterPressed();
						}
						else {
							bool temp = false;
							i.updatebool(temp);
							this->isPressedKey = false;
						}
					}
				}
				else if (this->isPaused == true) {
					if (mousePos.x >= 400.f && mousePos.x <= 700.f && mousePos.y >= 500.f && mousePos.y <= 600.f) {
						this->isPaused = false;
					}
					if (mousePos.x >= 800.f && mousePos.x <= 1100.f && mousePos.y >= 500.f && mousePos.y <= 600.f) {
						this->clean();
						this->state = GameState::MAIN;
					}
				}
				break;
			}

		}
	}
	else if (this->isGameOver == true) {
		while (window->pollEvent(this->ev)) {
			switch (this->ev.type) {
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::MouseButtonPressed:
				if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 400.f && mousePos.y <= 500.f) {
					this->clean();
					this->state = GameState::MAIN;
				}
				if (this->won == false) {
					if (mousePos.x >= 600.f && mousePos.x <= 900.f && mousePos.y >= 550.f && mousePos.y <= 650.f) {
						this->clean();
						this->currentPlayerID(this->currentQuoteID);
					}
				}
				break;
			}
		}
	}
}
//Method that returns gamestate
GameState Play::returnGameState()
{
	return this->state;
}
//Method that sets gamestate
void Play::setState(GameState sentState)
{
	this->state = sentState;
}
//Method that updates which level is going to be played now.
int Play::currentPlayerID(int i)
{
	this->difficulty = std::rand()%3;
	this->currentQuoteID = i;
	this->currentQuote = database.getQuote(currentQuoteID);
	std::cout << currentQuote.getquote() << std::endl << "Dificulty: " << difficulty << std::endl;
	initQuote();
	return 0;
}
//Method that this class does not use.
void Play::updateDatabase(PlayerDatabase& data)
{
}
//Method that checks if game has been won.
bool Play::isWon()
{
	if (this->won == true) {
		this->won = false;
		return true;
	}
	else
		return false;
}

