#ifndef CARD_DB_H
#define CARD_DB_H

#include <vector>
#include <string>

#include "card.h"
#include "database.h"

template<typename T>
using vector = std::vector<T>;
using std::string;

class CardDB : public Database<Card> {
    private:
    vector<Card> card_db;

    public:
    CardDB(string file_path);
    Card load(int id);
    size_t size();
    void print();
};
#endif
