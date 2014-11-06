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


#include "Player.h"
#include <iostream>
#include <sstream>

Player::Player() {
}

Player::~Player() {
}

bool Player::takeHit(){
	char c;
	cout << "Hit? (y/n): ";
	cin >> c;
	if(c == 'y' || c == 'Y')
		return true;
	return false;
}

/*
string Player::getHandReport(string s){
	int i = 1;
	int value = 0;
	stringstream sstm;
	list<Card>::iterator iterator;
	sstm << s << endl;
	for (iterator = hand.begin(); iterator != hand.end(); ++iterator) {
		Card c = *iterator;
		sstm << "Card " << i++ << ": " << iterator->getName() << " of " << iterator->getSuit() << "\n";
		value += iterator->getValue();
	}
	sstm << "Value: " << value << "\n";
	return sstm.str();
}
*/

void Player::process(Deck &deck, int num, string dealerShows){
//	checkAces();
	if(getHandValue() == 21){
		blackjack = true;
		cout << getHandReport() << endl << "Blackjack!! Collect your dough." << endl;
		//reportResults();
//	} else if(this.canAndWantsSplit(num,dealerShow)){
//		this.processSplit(deck,num,dealerShow);
//		this.hasSplit = true;
	} else {
		while(getHandValue() < 21){
			stringstream sstm;
			sstm << "\nPlayer "
					<< num
					<< ":\n"
					<< getHandReport()
					<< dealerShows  << "\n";
					// "\nClick 'OK' for hit, 'Cancel' to stay.";
					//System.out.println(s);
			cout << sstm.str();
			if(takeHit()){
				this->addCard(*deck.nextCard());
			}
			else break;
/*
			if(checkBusted()){
			s = "Player " + num + ": Value: " + getHandValue() + "\n"
			+ getHandReport()
			+ "Sorry you're busted.";
			System.out.println(s);
			break;
			} else if(getHandValue() == 21){
			s = "Player " + num + ": Value: " + this.getHandValue() + "\n"
			+ getHandReport()
			+ "21!";
			System.out.println(s);
			break;
			}
			}
			else break;
			}
			}

*/
//			}
		}
	}
	return;
}
