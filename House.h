
#include "GenericPlayer.h"


class House : public GenericPlayer
{
public:
    House(const std::string& name = "House");

    // показывает, хочет ли дилер продолжать брать карты
    bool isHitting() const override;

    // переворачивает первую карту
    void flipFirstCard();
};
