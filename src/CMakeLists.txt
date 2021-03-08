cmake_minimum_required(VERSION 3.10)

add_library(Card STATIC card.cpp)
add_library(CardDB STATIC card_db.cpp)
add_library(Deck STATIC deck.cpp)
add_library(DeckDB STATIC deck_db.cpp)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} Card CardDB Deck DeckDB)
