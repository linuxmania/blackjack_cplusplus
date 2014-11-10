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


#include "Participant.h"
#include "Card.h"
#include <string>
#include <sstream>

Participant::Participant() {
	busted = false;
}

Participant::~Participant() {
}

bool Participant::checkBusted(){
	if(getHandValue() > 21){
		busted = true;

		list<Card>::iterator iterator;
		for (iterator = hand.begin(); iterator != hand.end(); ++iterator) {
			if(iterator->getOrder() == 1 && iterator->getValue() == 11){
				iterator->setValue(1);
				busted = false;
				break;
			}
		}
	}
	return busted;
}

int Participant::getHandValue(){
	int value = 0;
	list<Card>::const_iterator iterator;
	for (iterator = hand.begin(); iterator != hand.end(); ++iterator) {
		value += iterator->getValue();
	}
	return value;
}

const list<Card>& Participant::getHand() const {
	return hand;
}

void Participant::setHand(const list<Card>& hand) {
	this->hand = hand;
}

void Participant::addCard(Card c){
	this->hand.push_back(c);
}

string Participant::getHandReport(){
	int i = 1;
	int value = 0;
	stringstream sstm;
	list<Card>::iterator iterator;
	for (iterator = hand.begin(); iterator != hand.end(); ++iterator) {
		Card c = *iterator;
		sstm << "Card " << i++ << ": " << iterator->getName() << " of " << iterator->getSuit() << "\n";
		value += iterator->getValue();
	}
	sstm << "Value: " << value << "\n";
	return sstm.str();
}

bool Participant::isBusted() const {
	return busted;
}

void Participant::setBusted(bool busted) {
	this->busted = busted;
}
