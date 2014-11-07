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
#include <stdlib.h>
#include <iterator>
using namespace std;
#include "Deck.h"

Deck::Deck() {
	Card* c;
	string suit;

	for(int i=0; i<52; i++){
		if(i<13) suit = "Diamonds";
		else if(i<26) suit = "Clubs";
		else if(i<39) suit = "Hearts";
		else suit = "Spades";
		c = new Card((i%13) + 1, suit);
		cards.push_front(*c);
	}
	deckIterator = cards.begin();
}

const list<Card>& Deck::getCards() const {
	return cards;
}

Deck::~Deck() {
}

Card* Deck::nextCard(){
	Card c = *deckIterator;
	Card* p_c = new Card(c.getOrder(),c.getSuit());
	deckIterator++;
	return p_c;
}

void Deck::shuffle(){
	for(int i=0; i<52 ; i++){
		int j = rand() % this->cards.size();
		advance(deckIterator ,j);
		Card c = *deckIterator;
		Card* p_c = new Card(c.getOrder(),c.getSuit());
		shuffledDeck.push_back(*p_c);
		cards.erase(deckIterator);
		deckIterator = cards.begin();
	}
	cards = shuffledDeck;
}
