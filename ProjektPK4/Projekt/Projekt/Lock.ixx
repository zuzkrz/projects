#include "pch.h"
export module Lock;

export namespace Lock {
	//Module that returns vector of Lock Position in quote
	std::vector<int> returnLockPosition(std::vector<bool> sent) {
		std::vector<int> tempPos, toReturn;
		for (int i = 0; i < sent.size(); i++) {
			if (sent[i] == true) {
				tempPos.push_back(i);
			}
		}
		for (int i = 0; i < 3; i++) {
			int rand = std::rand() % tempPos.size();
			toReturn.push_back(tempPos[rand]);
			tempPos[rand] = tempPos[tempPos.size() - 1];
			if (rand +1 != tempPos.size())
				tempPos[rand + 1] = tempPos[tempPos.size() - 2];
			if (rand-1 >= 0)
				tempPos[rand - 1] = tempPos[tempPos.size() - 3];
			tempPos.pop_back();
			tempPos.pop_back();
			tempPos.pop_back();
		}
		std::ranges::sort(toReturn, std::ranges::less{});
		return toReturn;
	};
}