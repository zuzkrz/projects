#pragma once
#include <string>

namespace zk {
	class LogData {
		std::string password;
		int ID;
	public:
		LogData(const int id, const std::string pass) : ID(id), password(pass) {}
		std::string getPassword() const noexcept {
			return password;
		}
		int getID() const noexcept {
			return ID;
		}
		void setPassword(std::string newPassword) {
			password = newPassword;
		}
	};
}