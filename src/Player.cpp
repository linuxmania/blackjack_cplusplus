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

Player::Player(string number) {
	this->number = number;
	blackjack = false;
	win = false;
	lose = false;
	tie = false;
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

bool Player::isBlackjack() const {
	return blackjack;
}

void Player::setBlackjack(bool blackjack) {
	this->blackjack = blackjack;
}

bool Player::isLose() const {
	return lose;
}

void Player::setLose(bool lose) {
	this->lose = lose;
}

bool Player::isTie() const {
	return tie;
}

void Player::setTie(bool tie) {
	this->tie = tie;
}

bool Player::isWin() const {
	return win;
}

void Player::setWin(bool win) {
	this->win = win;
}

const string& Player::getNumber() const {
	return number;
}

void Player::setNumber(const string& number) {
	this->number = number;
}

void Player::reportResults(bool dealerBusted, int dealerValue){
	cout << "Player " << number;
	if(blackjack)
		cout << " Blackjack! collect your dough." << endl;
	else if(busted)
		cout << " Sorry you're busted." << endl;
	else if(win){
		cout << " Winner " << getHandValue() << " - ";
		if(dealerBusted)
			cout << "Dealer is busted." << endl;
		else cout << dealerValue << "." << endl;
	} else if(tie)
		cout << " Tie " << getHandValue() << " - " << dealerValue << "." << endl;
	else cout << " Loser " << getHandValue() << " - " << dealerValue << "." << endl;
}

void Player::process(Deck &deck, int num, string dealerShows){
//	checkAces();
	if(getHandValue() == 21){
		blackjack = true;
		cout << getHandReport() << endl << "Blackjack!! Collect your dough." << endl;
//	} else if(this.canAndWantsSplit(num,dealerShow)){
//		this.processSplit(deck,num,dealerShow);
//		this.hasSplit = true;
	} else {
		while(getHandValue() < 21){
			cout << "\nPlayer "	<< num << ":\n" << getHandReport() << dealerShows  << "\n";
			if(takeHit()){
				this->addCard(*deck.nextCard());
				if(checkBusted()){
					cout << "\nPlayer " << num << ": Value: " << getHandValue() << endl;
					cout << getHandReport();
					cout << "Sorry you're busted." << endl;
				} else if(getHandValue() == 21){
					cout << "Player " << num << ": Value: " << getHandValue() << endl;
					cout << getHandReport() << "21!" << endl;
				}
			}
			else break;
		}
	}
	return;
}
