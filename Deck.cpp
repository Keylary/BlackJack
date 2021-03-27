#include "Deck.h"
#include <algorithm>
#include <iostream>
#include <ctime>

Deck::Deck()
{
    m_cards.reserve(52);
    populate();
}

Deck::~Deck()
{}

void Deck::populate()
{
    clear();
    // ������� ����������� ������
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
    {
        for (int r = Card::ACE; r <= Card::KING; ++r)
        {
            add(new Card(static_cast<Card::rank>(r),
                static_cast<Card::suit>(s)));
        }
    }
}

void Deck::shuffle()
{
    srand(static_cast<unsigned int>(time(0)));
    std::random_shuffle(m_cards.begin(), m_cards.end());
}

// ������� ����� �������� ��� � ��������� ���� Player, ��� � House
void Deck::additionalCards(GenericPlayer& aGenericPlayer)
{
    std::cout << std::endl;
    //���������� ��������� ����� �� ��� ���, ���� � ������ �� ���������
    // ������� ��� ���� �� ����� ����� ��� ���� �����
    while (!(aGenericPlayer.isBusted()) && aGenericPlayer.isHitting())
    {
        deal(aGenericPlayer);
        std::cout << aGenericPlayer << std::endl;

        if (aGenericPlayer.isBusted())
        {
            aGenericPlayer.bust();
        }
    }
}

void Deck::deal(Hand& aHand)
{
    if (!m_cards.empty())
    {
        aHand.add(m_cards.back());
        m_cards.pop_back();
    }
    else
    {
        std::cout << "Out of cards. Unable to deal.";
    }
}