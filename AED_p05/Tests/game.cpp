#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
using namespace std;


unsigned int Game::numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
	this->kids = l2;
}

//-----------------------------------------------------------------

// TODO
void Game::addKid(const Kid k1) {
    kids.push_back(k1);
}

// TODO
list<Kid> Game::getKids() const {
    return kids;
}

// TODO
void Game::setKids(const list<Kid>& l1) {
    for (auto it = l1.begin(); it!= l1.end();it++){
        Kid k1;
        kids.push_back(*it);
    }
}

// TODO
Kid Game::loseGame(string phrase) {
    list<Kid>::iterator it = kids.begin();
    int num = numberOfWords(phrase);
    while (kids.size() > 1) {
        int jumps= num;
        while(kids.size()<jumps){
            jumps-=kids.size();
        }
        for (int i = 0; i < jumps; i++) {
            it++;
            if(i > kids.size()-1){
                it=kids.begin();
            }
        }
        kids.erase(it);
    }
    return kids.front();
}
// TODO
list<Kid> Game::removeOlder(unsigned id) {
    return (list<Kid>());
}

// TODO
queue<Kid> Game::rearrange() {
    return(queue<Kid>());
}

// TODO
bool Game::operator==(Game& g2) {
	return true;
}

// TODO
list<Kid> Game::shuffle() const {
	return (list<Kid>());
}
