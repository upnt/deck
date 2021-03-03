#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "deck_db.h"
#include "deck.h"
#include "database.h"

using std::string;
using std::ifstream;
using std::filesystem::directory_iterator;
using std::cout;
using std::endl;

DeckDB::DeckDB(string dir_path) : dir_path(dir_path){
    for(auto& i : directory_iterator(dir_path)){
        names.push_back(i.path().filename().string());
    }
}

Deck DeckDB::load(int id) {
    auto file_path = dir_path / names[id];
    ifstream file(file_path.string());
    string line;
    
    Deck deck;
    while(std::getline(file, line)) {
        deck.add(Card(line));
    }

    return deck;
}

size_t DeckDB::size() {
    return names.size();
}

void DeckDB::print() {
    for(int i = 0; i < names.size(); i++) {
        string name = names[i];
        cout << i << ": " << name << endl;
    }
}
