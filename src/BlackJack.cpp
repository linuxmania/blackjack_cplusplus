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


#include <iostream>
using namespace std;
#include "Deck.h"
#include "Game.h"

int main() {
/*
	cout << "!!!Hello Wold!!!" << endl; // prints !!!Hello World!!!
	Deck* d = new Deck();
	cout << "!!!Hello Wold2!!!" << endl; // prints !!!Hello World!!!

	list<Card>::const_iterator iterator;
	for (iterator = d->getCards().begin(); iterator != d->getCards().end(); ++iterator) {
		Card c = *iterator;
		cout << iterator->getName() << " of " << iterator->getSuit() << endl;
	}

	d->shuffle();
	list<Card> list = d->getCards();
	int i = list.size();
	for (iterator = d->getCards().begin(); iterator != d->getCards().end(); ++iterator) {
		Card c = *iterator;
		cout << iterator->getName() << " of " << iterator->getSuit() << endl;
	}

*/
	while(1){
		Game g;
		if(!g.play()) break;
	}

	return 0;
}
