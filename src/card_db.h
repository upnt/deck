#ifndef CARD_DB_H
#define CARD_DB_H

#include <vector>
#include <string>
#include <fstream>

#include "card.h"
#include "database.h"

template<typename T>
using vector = std::vector<T>;
using std::string;
using std::ifstream;

class CardDB : public Database<Card> {
    private:
    vector<Card> card_db;

    public:
    CardDB(string file_path) {
        ifstream file(file_path);
        string line;

        while(std::getline(file, line)) {
            card_db.push_back(Card(line));
        }
    }

    Card load(int id) {
        return card_db[id];
    }

    size_t size() {
        return card_db.size();
    }

    void print() {
        for(int i = 0; i < card_db.size(); i++) {
            cout << i << ": " << card_db[i].get_name() << endl;
        }
    }
};

#endif
