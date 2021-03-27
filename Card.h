#pragma once
#include <iostream>

class Card
{
public:
    enum rank {
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING
    };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    Card(rank r = ACE, suit s = SPADES, bool ifu = true);

    int getValue() const;
    void flip() { m_isFaceUp = !(m_isFaceUp); }

    friend std::ostream& operator<<(std::ostream& os, const Card& aCard);

private:
    rank m_rank;
    suit m_suit;
    bool m_isFaceUp;
};

std::ostream& operator<<(std::ostream& os, const Card& aCard);