#pragma once
#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand
{
public:
    Deck();

    virtual ~Deck();

    // создает стандартную колоду из 52 карт
    void populate();

    // тасует карты
    void shuffle();

    // раздает одну карту в руку
    void deal(Hand& aHand);

    //дает дополнительные карты игроку
    void additionalCards(GenericPlayer& aGenericPlayer);
};




