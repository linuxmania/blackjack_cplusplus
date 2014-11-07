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


#include "Game.h"
#include <string>
#include <iostream>

Game::Game() {
}

Game::~Game() {
}

void  Game::reportResults(){
	list<Player>::iterator iterator;
	cout << endl;
	int i = 1;
	string s;
	for (iterator = players.begin(); iterator != players.end(); ++iterator) {
		cout << "Player " << i  << ":\n" << iterator->getHandReport() << endl;
		i++;
	}
	cout << "Dealer:\n" << dealer.getHandReport() << endl << endl;

/*
	if(p.hasSplit){
			p.reportSplitResults(dealer.getHandValue() ,
					String.valueOf(players.indexOf(p) + 1));
		} else {
			if(!p.busted && !p.blackjack){
				if(dealer.busted)
					p.win = true;
				else if(p.getHandValue() > dealer.getHandValue())
					p.win = true;
				else if(p.getHandValue() == dealer.getHandValue())
					p.tie = true;
				else p.lose = true;
			}
			System.out.println("");
			System.out.println("Player " + (players.indexOf(p) + 1));
			p.reportResults();
		}
	}
	System.out.println("");
*/
}



int Game::getNumPlayers(){
	int i;
	cout << "Number of Players(1 - 5): ";
	cin >> i;
	return i;
}

Deck& Game::getDeck(){
	return deck;
}

bool Game::play(){
	int num = getNumPlayers();
	if(num == 0)
		return false;

	list<Card>::const_iterator iterator1;
	for (iterator1 = deck.getCards().begin(); iterator1 != deck.getCards().end(); ++iterator1) {
		Card c = *iterator1;
		cout << iterator1->getName() << " of " << iterator1->getSuit() << endl;
	}

	deck.shuffle();

	for (iterator1 = deck.getCards().begin(); iterator1 != deck.getCards().end(); ++iterator1) {
		Card c = *iterator1;
		cout << iterator1->getName() << " of " << iterator1->getSuit() << endl;
	}

	Player* p;
	for(int i=0; i < num; i++){
		p = new Player();
		players.push_front(*p);
	}

	deal();

	int j = 1;
	list<Player>::iterator iterator;
	for (iterator = players.begin(); iterator != players.end(); ++iterator) {
		iterator->process(getDeck(),j++, dealer.reportShowing());
	}

	dealer.process(getDeck());
	reportResults();

	return true;
}

void Game::deal(){

	list<Player>::iterator iterator;
	Player player;

	for(int i =0; i < 2; i++){
		for (iterator = players.begin(); iterator != players.end(); ++iterator) {
			iterator->addCard(*deck.nextCard());
		}
		dealer.addCard(*deck.nextCard());
	}

	/*
	for (iterator = players->getCards().begin(); iterator != d->getCards().end(); ++iterator) {

	for(Player p : players){
		p.addCard(deck.nextCard());
	}
	dealer.addCard(deck.nextCard());
	for(Player p : players){
		p.addCard(deck.nextCard());
		System.out.println("");
		System.out.println("Player " + (players.indexOf(p) + 1));
		p.checkBusted();
		p.reportHand();
		if(p.getHandValue() == 21) p.blackjack = true;
		p.reportResults();
	}
	dealer.addCard(deck.nextCard());
	System.out.println("");
	dealer.reportInitialHand();
*/
	return;
}

