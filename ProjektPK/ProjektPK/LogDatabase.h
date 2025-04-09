#pragma once
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "LogData.h"

namespace zk {
	class LogDatabase {
		std::vector<zk::LogData> log_database;
	public:
		LogDatabase(std::vector<zk::LogData> data) {
			log_database = data;
		}
		std::vector<zk::LogData> getLogDatabase() {
			return log_database;
		}
		void createDatabase() {
			std::ifstream plik;
			plik.open("log_data.txt");
			if (plik.is_open())
			{
				std::vector<std::string> Vpas;
				std::vector<int> Vid;
				std::string line;
				while (std::getline(plik, line))
				{
					std::string pass;
					int id;
					std::stringstream ss(line);
					if (ss >> id) {
						ss >> pass;
						Vpas.push_back(pass);
						Vid.push_back(id);
					}
				}
				for (int k = 0; k < Vpas.size(); k++) {
					log_database.push_back(zk::LogData(Vid[k], Vpas[k]));
				}
				plik.close();
			}
			else
				throw "Could't find an Employee Database file.";
		}
		int findEmpIndex(int id) {
			int n;
			for (int i = 0; i < log_database.size(); i++) {
				if (log_database[i].getID() == id) {
					n = i;
					break;
				}
				else {
					n = -1;
				}
			}
			return n;
		}
		std::string getPass(int index) {
			std::string pass = log_database[index].getPassword();
			return pass;
		}
		void rewriteDatabase() {
			std::ofstream plik("log_data.txt", std::ofstream::trunc);
			for (auto& k : log_database) {
				std::string idnum = std::to_string(k.getID());
				std::string logdat = idnum + " " + k.getPassword() + "\n";
				plik << logdat;
			}
			plik.close();
		}

		void addLog(std::string password, int id) {
			zk::LogData newLog(id, password);
			log_database.push_back(newLog);
			rewriteDatabase();
		}
	};
}