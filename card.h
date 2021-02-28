#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Card {
    private:
    string name;

    public:
    Card() : name("") {
    }

    Card(string name) : name(name) {
    }

    string get_name() {
        return name;
    }
};
#endif
