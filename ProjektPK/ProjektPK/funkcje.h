#pragma once
#include <iostream>
#include "ErrorDatabase.h"
#include <string>
#include <sstream>

void welcome() {
	std::cout << "Hello! \n If you want to report a problem type: report. \n If you are an employee and want to login type: login.\n If you want to exit, type: exit \n";
}
void separator() {
	std::cout << std::endl << "-------------------------------------------------------------------------------------------" << std::endl << std::endl;
}

//funkcja dodaj¹ca b³¹d
void reportBug(zk::ErrorDatabase &error_database) {
	separator();
	std::cout << std::endl << "Choose the type of the problem: " << "\n -> For Account problem type: account" << "\n -> For Payment problem type: payment" <<
		"\n -> For In-Game problem type: ingame" << "\n -> For Other type problem problem type: other \n";
	bool temp = true;
	int type_;
	while (temp == true)
	{
		std::string type;
		std::cin >> type;
		if (type == "account") {
			type_ = 1;
			temp = false;
		}
		else if (type == "payment") {
			type_ = 2;
			temp = false;
		}
		else if (type == "ingame") {
			type_ = 3;
			temp = false;
		}
		else if (type == "other") {
			type_ = 4;
			temp = false;
		}
		else {
			std::cout << "\nIncorrect type. Please enter a type again." << std::endl;
		}
	}
	std::string contact_;
	std::cout << "\nPlease enter your mail: ";
	while (contact_.size() == 0) {
		getline(std::cin, contact_);
		contact_.erase(remove(contact_.begin(), contact_.end(), ' '), contact_.end());
	}
	
	std::cout << "\nEnter title: " << std::endl;
	std::string title_;
	while (title_.size() == 0) {
		getline(std::cin, title_);
	}
	std::cout << "\n\nWould you like to describe a problem? \n -> Enter yes or no" << std::endl;
	std::string desc_;
	while (temp == false) {
		std::string temp1;
		std::cin >> temp1;
		if (temp1 == "yes") {
			std::cout << "\nType in description:" << std::endl;
			while (desc_.size() == 0) {
				std::getline(std::cin, desc_);
			}
			error_database.addError(title_, type_, contact_, desc_);
			temp = true;
		}
		else if (temp1 == "no") {
			error_database.addError(title_, type_, contact_);
			temp = true;
		}
		else {
			std::cout << "\n Incorrect command. Enter again: " << std::endl;
		}
	}
	std::cout << "\n\nThank you for your report." << std::endl;
	separator();
}

// funkcja loguj¹ca
void login(zk::EmpDatabase& emp_database, zk::LogDatabase& log_database, int& n, bool &test) {
	std::cout << "\nType ID: ";
	std::cin >> n;
	int b = emp_database.findEmpIndex(n);
	int a;
	if (b != -1) {
		a = log_database.findEmpIndex(n);
		std::string pass;
		if (a != -1) {
			bool temp = true;
			while (temp == true) {
				std::cout << "\nType password: ";
				std::cin >> pass;
				if (pass == log_database.getPass(a)) {
					std::cout << "Welcome " << emp_database.ShowEmp(b) << std::endl;
					test = true;
					temp = false;
				}
				else {
					std::cout << "\nWrong password.";
				}
			}
		}
		else {
			std::string pass1, pass2;
			bool temp = true;
			while (temp == true) {
				std::cout << "\nYou have not logged in yet. Please create new password. " << std::endl <<
					"Enter new password: ";
				std::cin >> pass1;
				std::cout << "Repeate new password: ";
				std::cin >> pass2;
				if (pass1 == pass2) {
					log_database.addLog(pass1, n);
					std::cout << "\nWelcome " << emp_database.ShowEmp(b) << std::endl;
					test = true;
					temp = false;
				}
				else {
					std::cout << "\nPasswords are different! Please try again." << std::endl;
				}
			}

		}
	}
	else {
		std::cout << "\nThere is no such employee!" << std::endl;
		separator();
	}
}

//sprawdz ile b³êdów ma poszczegolna kategoria

// sprawdz ile bledow masz do zrobienia
  // task done

