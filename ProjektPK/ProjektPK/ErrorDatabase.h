#pragma once
#include<vector>
#include<fstream>
#include <sstream>
#include "Errors.h"

namespace zk {
	class ErrorDatabase {
		std::vector<zk::Error> error_database;
	public:
		ErrorDatabase(std::vector<zk::Error> data) {
			error_database = data;
		}
		std::vector<zk::Error> getErrorDatabase() {
			return error_database;
		}

		void createDatabase() {
			std::ifstream plik;
			plik.open("error_database.txt");
			if (plik.is_open())
			{
				std::vector<std::string> Vdes;
				std::vector<std::string> Vtit;
				std::vector<int> Vtyp;
				std::vector<std::string> Vcon;
				std::vector<int> Vid;
				std::vector<int> Vbo;
				int j = 0;
				std::string line;
				while (std::getline(plik, line))
				{
					std::string contact, tytul, opis, znak;
					int typ, id, boo;
					std::stringstream ss(line);
					if (j == 0) {
						if (ss >> znak) {
							if (znak == "1") typ = 1;
							else if (znak == "2") typ = 2;
							else if (znak == "3") typ = 3;
							else typ = 4;
							ss >> id;
							ss >> boo;
							ss >> contact;
							Vcon.push_back(contact);
							Vid.push_back(id);
							Vbo.push_back(boo);
							Vtyp.push_back(typ);
							j++;
						}
					}
					else if ((j - 1) == 0) {
						Vtit.push_back(line);
						j++;
					}
					else if ((j - 2) == 0) {
						Vdes.push_back(line);
						j = 0;
					}
				}
				for (int k = 0; k < Vtyp.size(); k++) {
					bool temp;
					if (Vbo[k] == 1) temp = true;
					else temp = false;

					error_database.push_back(zk::Error(Vtit[k], Vcon[k], Vtyp[k], Vid[k], Vdes[k], temp));
				}
				plik.close();
			}

			else
				throw "Could't find an Error Database file.";
		}
		void rewriteDatabase() {
			std::ofstream plik("error_database.txt", std::ofstream::trunc);
			for (auto& k : error_database) {
				std::string type = std::to_string(k.getType());
				std::string idnum = std::to_string(k.getID());
				std::string boo = std::to_string(k.isdone());
				std::string person = type + " " + idnum + " " + boo + " " + k.Contact() + "\n" + k.Title() + "\n" + k.Description() + "\n";
				plik << person;
			}
			plik.close();
		}
		void addError(std::string title, int type, std::string contact, std::string description) {
			int oldid = error_database.size();
			int newID = error_database[oldid - 1].getID() + 1;
			zk::Error newEmp(title, contact, type, newID, description);
			error_database.push_back(newEmp);
			rewriteDatabase();
		}
		void addError(std::string title, int type, std::string contact) {
			int oldid = error_database.size();
			int newID = error_database[oldid - 1].getID() + 1;
			zk::Error newEmp(title, contact, type, newID);
			error_database.push_back(newEmp);
			rewriteDatabase();
		}

		int findErrorIndex(int id) {
			int n;
			for (int i = 0; i < error_database.size(); i++) {
				if (error_database[i].getID() == id) {
					n = i;
					break;
				}
			}
			return n;
		}
		void taskDone(int id) {
			int n = findErrorIndex(id);
			error_database[n].taskDone();
			rewriteDatabase();
		}

	};


}