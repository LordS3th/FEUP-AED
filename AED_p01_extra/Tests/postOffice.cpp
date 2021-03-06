#include "postOffice.h"
#include <string>

 using namespace std;
PostOffice::PostOffice(string firstZCode, string lastZCode):
								firstZipCode(firstZCode), lastZipCode(lastZCode)
{}
PostOffice::PostOffice() {}

void PostOffice::addMailToSend(Mail *m) {
	mailToSend.push_back(m);
}

void PostOffice::addMailToDeliver(Mail *m) {
	mailToDeliver.push_back(m);
}

void PostOffice::addPostman(const Postman &p){
	postmen.push_back(p);
}

vector<Mail *> PostOffice::getMailToSend() const {
	return mailToSend;
}

vector<Mail *> PostOffice::getMailToDeliver() const {
	return mailToDeliver;
}

vector<Postman> PostOffice::getPostman() const {
	return postmen;
}


//--------

// TODO
vector<Mail *> PostOffice::removePostman(string name) {
	for (int i=0; i < postmen.size(); i++){
        if (postmen[i].getName() == name){
            vector<Mail *> m;
            m= postmen[i].getMail();
            postmen.erase( postmen.begin()+i);
            return m;
        }
    }
    vector<Mail *> empty;
    return empty;
}

// TODO
vector<Mail *> PostOffice::endOfDay(unsigned int &balance) {
    vector<Mail *> other_stations;
    int value=0;
	for (int i =0; i < mailToSend.size(); i++) {
         value += mailToSend[i]->getPrice();
         if (mailToSend[i]->getZipCode() > firstZipCode && mailToSend[i]->getZipCode() < lastZipCode) {
          addMailToDeliver(mailToSend[i]);
        } else {
        other_stations.push_back(mailToSend[i]);
         }
    }
    mailToSend={};
    balance=value;
    return other_stations;
}



Postman PostOffice::addMailToPostman(Mail *m, string name) {
    NoPostmanException a;
    a.name=name;
	for (int i=0; i <postmen.size();i++){
        if (postmen[i].getName() == name){
            postmen[i].addMail(m);
            return postmen[i];
        }
    }
    throw a;
}

