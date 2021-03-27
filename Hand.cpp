#include "Hand.h"
void Hand::add(Card* pCard)
{
    m_cards.push_back(pCard);
}

void Hand::clear()
{
    // проходит по вектору, освобождая всю память в куче
    std::vector<Card*>::iterator iter = m_cards.begin();
    for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
    {
        delete* iter;
        *iter = 0;
    }
    m_cards.clear();
}


int Hand::getTotal() const
{
    // если карт в руке нет, возвращает значение 0
    if (m_cards.empty())
        return 0;

    //если первая карта имеет значение 0, то она лежит рубашкой вверх:
    // вернуть значение 0
    if (m_cards[0]->getValue() == 0)
        return 0;

    // находит сумму очков всех карт, каждый туз дает 1 очко
    int total = 0;
    std::vector<Card*>::const_iterator iter;
    for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
    {
        total += (*iter)->getValue();
    }

    // определяет, держит ли рука туз
    bool containsAce = false;
    for (iter = m_cards.begin(); iter != m_cards.end(); ++iter)
    {
        if ((*iter)->getValue() == Card::ACE)
        {
            containsAce = true;
        }
    }

    // если рука держит туз и сумма довольно маленькая, туз дает 11 очков
    if (containsAce && total <= 11)
    {
        // добавляем только 10 очков, поскольку мы уже добавили
        // за каждый туз по одному очку
        total += 10;
    }

    return total;
}