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
#include <sstream>

Game::Game() {
}

Game::~Game() {
}

void  Game::reportResults(){
	list<Player>::iterator iterator;
	cout << endl;
	string s;
	for (iterator = players.begin(); iterator != players.end(); ++iterator) {
		if(!iterator->isBusted() && !iterator->isBlackjack()){
			if(dealer.isBusted())
				iterator->setWin(true);
			else if(iterator->getHandValue() > dealer.getHandValue())
				iterator->setWin(true);
			else if(iterator->getHandValue() == dealer.getHandValue())
				iterator->setTie(true);
			else iterator->setLose(true);
		}

		iterator->reportResults(dealer.isBusted(),dealer.getHandValue());
	}

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
		stringstream sstm;
		sstm << i+1;
		p = new Player(sstm.str());
		players.push_back(*p);
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

	for(int i =0; i < 2; i++){
		for (iterator = players.begin(); iterator != players.end(); ++iterator) {
			iterator->addCard(*deck.nextCard());
		}
		dealer.addCard(*deck.nextCard());
	}
	return;
}
