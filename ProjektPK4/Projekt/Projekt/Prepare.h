#pragma once
#include "pch.h"

bool prepareFunction() {
	bool temp = true;
	std::filesystem::path sciezka = std::filesystem::current_path() / "database";
	if (!std::filesystem::exists(sciezka)) {
		std::cerr << "Catalogue database does not exist!" << std::endl;
	}
	else {
		bool playerexist = true;
		bool quoteexist = true;
		for (auto& i : std::filesystem::directory_iterator(sciezka)) {
			std::string compare = i.path().filename().string();
			if (compare == "player.txt") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					playerexist = false;
				}

			}
			else if (compare == "Quotes.txt") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					quoteexist = false;
				}
			}
		}
		if (!quoteexist) {
			std::cerr << "Quote database does not exist!" << std::endl;
			return false;
		}
		if (!playerexist) {
			std::cerr << "Player database does not exist!" << std::endl;
			return false;
		}
	}
	sciezka = std::filesystem::current_path() / "font";
	if (!std::filesystem::exists(sciezka)) {
		std::cerr << "Catalogue font does not exist!";
	}
	else {
		bool font1 = true;
		bool font2 = true;
		for (auto& i : std::filesystem::directory_iterator(sciezka)) {
			std::string compare = i.path().filename().string();
			if (compare == "cryptofont.otf") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					font1 = false;
				}
			}
			else if (compare == "regularfont.ttf") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					font2 = false;
				}
			}
		}
		if (!font1) {
			std::cerr << "Cryptofont does not exist!" << std::endl;
			return false;
		}
		if (!font2) {
			std::cerr << "Regular font does not exist!" << std::endl;
			return false;
		}
	}
	sciezka = std::filesystem::current_path() / "png";
	if (!std::filesystem::exists(sciezka)) {
		std::cerr << "Catalogue png does not exist!";
	}
	else {
		bool help = true;
		bool help2 = true;
		bool icon = true;
		bool life = true;
		bool lifeLost = true;
		bool lock1 = true;
		bool lock1G = true;
		bool lock2 = true;
		bool lock2G = true;
		bool lock2L = true;
		bool lock2R = true;
		bool loginbckgrnd = true;
		bool pause = true;
		bool pauseClicked = true;
		bool playbckgrnd = true;
		bool statsbckgrnd = true;
		for (auto& i : std::filesystem::directory_iterator(sciezka)) {
			std::string compare = i.path().filename().string();
			if (compare == "help.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					help = false;
				}
			}
			else if (compare == "help2.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					help2 = false;
				}
			}
			else if (compare == "icon.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					icon = false;
				}
			}
			else if (compare == "life.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					life = false;
				}
			}
			else if (compare == "lifeLost.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					lifeLost = false;
				}
			}
			else if (compare == "lock1.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					lock1 = false;
				}
			}
			else if (compare == "lock1G.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					lock1G = false;
				}
			}
			else if (compare == "lock2.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					lock2 = false;
				}
			}
			else if (compare == "lock2G.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					lock2G = false;
				}
			}
			else if (compare == "lock2L.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					lock2L = false;
				}
			}
			else if (compare == "lock2R.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					lock2R = false;
				}
			}
			else if (compare == "loginbckgrnd.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					loginbckgrnd = false;
				}
			}
			else if (compare == "pause.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					pause = false;
				}
			}
			else if (compare == "pauseClicked.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					pauseClicked = false;
				}
			}
			else if (compare == "playbckgrnd.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					playbckgrnd = false;
				}
			}
			else if (compare == "statsbckgrnd.png") {
				temp = true;
				if (std::filesystem::file_size(i.path()) == 0) {
					temp = false;
					statsbckgrnd = false;
				}
				}
		}
		if (!help) {
			std::cerr << "Help does not exist!" << std::endl;
		}
		if (!help2) {
			std::cerr << "Help2 does not exist!" << std::endl;
			return false;
		}
		if (!icon) {
			std::cerr << "Icon does not exist!" << std::endl;
			return false;
		}
		if (!life) {
			std::cerr << "Life does not exist!" << std::endl;
			return false;
		}
		if (!lifeLost) {
			std::cerr << "LifeLost does not exist!" << std::endl;
			return false;
		}
		if (!lock1) {
			std::cerr << "Lock1 does not exist!" << std::endl;
			return false;
		}
		if (!lock1G) {
			std::cerr << "Lock1G does not exist!" << std::endl;
			return false;
		}
		if (!lock2) {
			std::cerr << "Lock2G does not exist!" << std::endl;
		}
		if (!lock2G) {
			std::cerr << "Lock2G does not exist!" << std::endl;
		}
		if (!lock2L) {
			std::cerr << "Lock2L does not exist!" << std::endl;
			return false;
		}
		if (!lock2R) {
			std::cerr << "Lock2R does not exist!" << std::endl;
			return false;
		}
		if (!loginbckgrnd) {
			std::cerr << "Loginbckgrnd does not exist!" << std::endl;
			return false;
		}
		if (!pause) {
			std::cerr << "Pause does not exist!" << std::endl;
			return false;
		}
		if (!pauseClicked) {
			std::cerr << "PauseClicked does not exist!" << std::endl;
			return false;
		}
		if (!playbckgrnd) {
			std::cerr << "Playbckgrnd does not exist!" << std::endl;
			return false;
		}
		if (!statsbckgrnd) {
			std::cerr << "Statsbckgrnd does not exist!" << std::endl;
			return false;
		}
	}
	return temp;
}