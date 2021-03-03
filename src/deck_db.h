#ifndef DECK_DB_H
#define DECK_DB_H

#include <vector>
#include <string>
#include <filesystem>

#include "deck.h"
#include "database.h"

template<typename T>
using vector = std::vector<T>;
using std::string;
using std::filesystem::path;


class DeckDB : public Database<Deck> {
    private:
    vector<string> names;
    path dir_path;

    public:
    DeckDB(string dir_path);
    Deck load(int id);
    size_t size();
    void print();
};

#endif
