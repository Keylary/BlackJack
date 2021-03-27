#pragma once
#include "Card.h"
#include <vector>

class Hand
{
public:
    Hand(){ m_cards.reserve(7); }
    ~Hand() { clear(); }

    void add(Card* pCard);

    void clear();
    int getTotal() const;

protected:
    std::vector<Card*> m_cards;
};

