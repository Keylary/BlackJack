#pragma once
#include <string>
#include "Deck.h"
#include "House.h"
#include "Player.h"

//!-> add class for project

class Game
{
public:
    Game(const std::vector<std::string>& names);

    ~Game();

    // проводит игру в Blackjack
    void play();

private:
    Deck m_deck;
    House m_house;
    std::vector<Player> m_players;
};




//template<class T>
//Game(const T& names)
//{
//    for (auto pName = names.begin(); pName != names.end(); ++pName)
//    {
//        m_players.push_back(Player(*pName));
//    }
//
//    m_deck.populate();
//    m_deck.shuffle();
//}