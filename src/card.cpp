#include "card.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

Card::Card() : name("") {
}

Card::Card(string name) : name(name) {
}

string Card::get_name() {
    return name;
}
