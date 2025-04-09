#pragma once
#include<vector>
#include<fstream>
#include <sstream>
#include "Employee.h"

namespace zk {
	class EmpDatabase {
		std::vector<zk::Employee> emp_database;
	public:
		EmpDatabase(std::vector<zk::Employee> data) {
			emp_database = data;
		}
		std::vector<zk::Employee> getEmpDatabase() {
			return emp_database;
		}

		void createDatabase() {
			std::ifstream plik;
			plik.open("emp_database.txt");
			if (plik.is_open())
			{
				std::vector<std::string> Vname;
				std::vector<std::string> Vsurn;
				std::vector<int> Vid;
				std::string line;
				while (std::getline(plik, line))
				{
					std::string name, surname, department;
					int id;
					std::stringstream ss(line);
					if (ss >> id) {
						ss >> name >> surname;
						Vname.push_back(name);
						Vsurn.push_back(surname);
						Vid.push_back(id);
					}
				}
				for (int k = 0; k < Vname.size(); k++) {
					emp_database.push_back(zk::Employee(Vid[k], Vname[k], Vsurn[k]));
				}
				plik.close();
			}
			else
				throw "Could't find an Employee Database file.";
		}
		int findEmpIndex(int id) {
			int n;
			for (int i = 0; i < emp_database.size(); i++) {
				if (emp_database[i].getID() == id) {
					n = i;
					break;
				}
				else {
					n = -1;
				}
			}
			return n;
		}
		std::string ShowEmp(int a) {
			std::stringstream ss;
			ss << emp_database[a].getName() << " " << emp_database[a].getSurname();
			return ss.str();
		}
	};
}