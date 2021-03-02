#ifndef CARD_H
#define CARD_H

#include <string>
using std::string;

class Card {
    private:
    string name;

    public:
    Card();
    Card(string name);
    string get_name();

};
#endif
