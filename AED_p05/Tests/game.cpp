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
    this->kids = l1;
}

// TODO
Kid Game::loseGame(string phrase) {
    list<Kid> new_list = kids;
    list<Kid>::iterator it;
    it=new_list.begin();
    int num= numberOfWords(phrase);
    while(new_list.size()>1) {
        int jumps = new_list.size()%num-1;
        for (int i = 0; i < jumps; i++) {
            if (it == prev(new_list.end())) {
                it = new_list.begin();
            } else {
                it++;
            }
        }
        if (it == prev(new_list.end())) {
            it = new_list.erase(it);
            it = new_list.begin();
        } else it = new_list.erase(it);
    }
    return new_list.front();
}
// TODO
list<Kid> Game::removeOlder(unsigned id) {
    list<Kid>::iterator it;
    list <Kid> res;
    for (it=kids.begin(); it!=kids.end();it++){
        if ((*it).getAge() > id){
            res.push_back(*it);
            kids.erase(it);
            it--;
        }
    }
    return res;
}

// TODO
queue<Kid> Game::rearrange() {
    queue<Kid> female;
    queue<Kid> male;
    queue<Kid> res;
    int n, m;
    list<Kid>::iterator it;
    for ( it=kids.begin() ; it!= kids.end();it++){
        if ((*it).getSex()== 'f'){
            female.push(*it);
        }
        else male.push(*it);
    }
    kids.clear();
    if (female.size() < male.size()){
        n=1;
        m=male.size()/female.size();
        }
    else {
        m=1;
        n=female.size()/male.size();
    }
    while(true){
        if (female.size()<n){
            break;
        }
        for (int i=1; i <=n;i++){
            kids.push_back(female.front());
            female.pop();
        }
        if (male.size()< m){
            break;
        }
        for (int i = 1; i <=m;i++){
            kids.push_back(male.front());
            male.pop();
        }
    }
    while (female.size()!=0){
        res.push(female.front());
        female.pop();
    }
    while (male.size()!=0){
        res.push(male.front());
        male.pop();
    }
    return (res) ;
}



// TODO
bool Game::operator==(Game& g2) {
    list<Kid>::iterator it_1, it_2;
    it_1=kids.begin();
    it_2=g2.kids.begin();
    for ( it_1; it_1 != kids.end(); it_1++, it_2++){
        if (!(*it_1 == *it_2)){
            return false;
        }
    }
    return true;
}

// TODO
list<Kid> Game::shuffle() const {
	return (list<Kid>());
}
