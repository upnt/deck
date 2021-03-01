#ifndef DECK_DB_H
#define DECK_DB_H

#include <vector>
#include <string>
#include <fstream>
#include <filesystem>

#include "deck.h"
#include "database.h"

template<typename T>
using vector = std::vector<T>;
using std::string;
using std::ifstream;
using std::filesystem::path;
using std::filesystem::directory_iterator;

class DeckDB : public Database<Deck> {
    private:
    vector<string> names;
    path dir_path;

    public:
    DeckDB(string dir_path) : dir_path(dir_path){
        for(auto& i : directory_iterator(dir_path)){
            names.push_back(i.path().filename().string());
        }
    }

    Deck load(int id) {
        auto file_path = dir_path / names[id];
        ifstream file(file_path.string());
        string line;
        
        Deck deck;
        while(std::getline(file, line)) {
            deck.add(Card(line));
        }

        return deck;
    }

    size_t size() {
        return names.size();
    }

    void print() {
        for(int i = 0; i < names.size(); i++) {
            string name = names[i];
            cout << i << ": " << name << endl;
        }
    }
};

#endif
