#pragma once
#include <string>
#include<sstream>

namespace zk {

	class Error {
		std::string title, description, contact;
		int error_type, error_id;
		bool isDone;
	public:
		Error(const std::string tytul, const std::string mail, const int type, const int err_id, const std::string description, const bool isdon) : title(tytul), contact(mail), error_type(type), error_id(err_id), description(description), isDone(isdon) {
		}
		Error(const std::string tytul, const std::string mail, const int type, const int err_id, const std::string description) : title(tytul), contact(mail), error_type(type), error_id(err_id), description(description), isDone(false) {
		}
		Error(const std::string tytul, const std::string mail, const int type, const int err_id) : title(tytul), contact(mail), error_type(type), error_id(err_id), description("Nie wprowadzono opisu."), isDone(false) {
		}
		~Error() {};
		// -----------------------------------------------------------
		std::string Title() const noexcept {
			return title;
		}
		int isdone() {
			if (isDone == true)	return 1;
			else return 0;
		}
		std::string Description() const noexcept {
			return description;
		}
		std::string Contact() const noexcept {
			return contact;
		}
		int getID() {
			return error_id;
		}

		int getType() {
			return error_type;
		}
		std::string Error_type() const noexcept {
			if (error_type == 1) {
				return "Account";
			}
			else if (error_type == 2) {
				return "Payment";
			}
			else if (error_type == 3) {
				return "In-Game";
			}
			else {
				return "Other";
			}
		}
		void taskDone() {
			isDone = true;
		}

		std::string Show_Me() {
			std::stringstream ss;
			ss << "Error ID: " << error_id << "\nType of error: " << this->Error_type() << "\nContact info: " << contact << "\nTitle: " << title << "\nDescription of an error:\n" << description << "\n";
			return (ss.str());
		}
		std::string Show_Basic() {
			std::stringstream ss;
			ss << "Error ID: " << error_id << "\nType of error: " << this->Error_type() << "\nTitle: " << title;
			return (ss.str());
		}

	};
}