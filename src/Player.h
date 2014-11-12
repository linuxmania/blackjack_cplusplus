/***************************

Copyleft [2014] [Daniel Spicer]

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

****************************/


#ifndef BJ_SRC_PLAYER_H_
#define BJ_SRC_PLAYER_H_

#include "Participant.h"
#include "Deck.h"

class Player: public Participant {
private:
	bool blackjack;
	bool win;
	bool lose;
	bool tie;
	bool hasSplit;

	bool takeHit();
	string number;
	bool canAndWantsSplit(string num, string dealerShows);
	void processSplit(Deck& deck,string num,string dealerShows);
	list<Player> splitPlayers;

public:
	Player(string number);
	virtual ~Player();
	void process(Deck &deck, string num, string dealerShows);
	bool isBlackjack() const;
	void setBlackjack(bool blackjack);
	bool isLose() const;
	void setLose(bool lose);
	bool isTie() const;
	void setTie(bool tie);
	bool isWin() const;
	void setWin(bool win);
	void reportResults(bool dealerBusted, int dealerValue);
	const string& getNumber() const;
	void setNumber(const string& number);
	void reportSplitResults(bool dealerBusted, int dealerValue, string num);
	bool isHasSplit() const;
	void setHasSplit(bool hasSplit);
};

#endif /* BJ_SRC_PLAYER_H_ */
