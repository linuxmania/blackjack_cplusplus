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


#ifndef BJ_SRC_PARTICIPANT_H_
#define BJ_SRC_PARTICIPANT_H_

#include <list>
#include "Card.h"
using namespace std;


class Participant {
private:

protected:
	bool busted;
	bool checkBusted();
	void checkAces();

public:
	Participant();
	virtual ~Participant();
	const list<Card>& getHand() const;
	void setHand(const list<Card>& hand);
	void addCard(Card);
	list<Card> hand;
	string getHandReport();
	int getHandValue();
	bool isBusted() const;
	void setBusted(bool busted);
};

#endif /* BJ_SRC_PARTICIPANT_H_ */
