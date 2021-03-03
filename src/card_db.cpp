#include <iostream>
#include <string>
#include <fstream>

#include "card_db.h"
#include "card.h"
#include "database.h"

using std::string;
using std::ifstream;

using std::cout;
using std::endl;

CardDB::CardDB(string file_path) {
    ifstream file(file_path);
    string line;

    while(std::getline(file, line)) {
        card_db.push_back(Card(line));
    }
}

Card CardDB::load(int id) {
    return card_db[id];
}

size_t CardDB::size() {
    return card_db.size();
}

void CardDB::print() {
    for(int i = 0; i < card_db.size(); i++) {
        cout << i << ": " << card_db[i].get_name() << endl;
    }
}
