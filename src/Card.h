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

#ifndef BJ_SRC_CARD_H_
#define BJ_SRC_CARD_H_

#include <string>
using namespace std;

class Card {
private:
	int value;
	int order;
	string name;
	string suit;

public:
	Card(int, string);
	virtual ~Card();
	const string& getName() const;
	int getValue() const;
	void setValue(int value);
	const string& getSuit() const;
	int getOrder() const;
};

#endif /* BJ_SRC_CARD_H_ */
