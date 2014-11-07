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

**************************/

#include "Dealer.h"
#include <sstream>
#include <iostream>


Dealer::Dealer() {
}

Dealer::~Dealer() {
}

bool Dealer::takeHit(){
	if(getHandValue() < 17) return true;
	return false;
}

void Dealer::process(Deck &deck){
//	dealer.checkAces();
	cout << endl << "Dealer has:\n" << getHandReport();
	while(!busted){
		if(takeHit()){
			addCard(*deck.nextCard());
			if(checkBusted())
				cout << "Dealer has busted!!\n";
//			cout << endl << "Dealer has:\n" << getHandReport();
//			reportNewCard();
//			if(checkBusted())
//				reportResults();
		} else break;
	}
	return;
}

string Dealer::reportShowing(){
	stringstream sstm;
	list<Card>::iterator iterator;
	iterator = this->hand.begin();
//	iterator = this->getHand().begin();
	sstm << "Dealer shows " << iterator->getName() << " of " << iterator->getSuit();
	return sstm.str();
}
