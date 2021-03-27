
#include "House.h"
#include <iostream>

House::House(const std::string& name) :
    GenericPlayer(name)
{}


bool House::isHitting() const
{
    return (getTotal() <= 16);
}

void House::flipFirstCard()
{
    if (!(m_cards.empty()))
    {
        m_cards[0]->flip();
    }
    else
    {
        std::cout << "No card to flip!\n";
    }
}