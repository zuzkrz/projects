#pragma once
#include <string>
#include<sstream>

namespace zk {
	class Employee {
		std::string name, surname;
		int ID;
	public:
		Employee(const int id, const std::string name, const std::string surname) : name(name), surname(surname), ID(id) {}
		
		
		std::string getName() const noexcept{
			return name;
		}
		std::string getSurname() const noexcept {
			return surname;
		}
		int getID() const noexcept {
			return ID;
		}
		std::string Show_Me() {
			std::stringstream ss;
			ss << "Employee ID: " << ID << "\nName: " << name << "\nSurname: " << surname << "\n";
			return (ss.str());
		}
};
}