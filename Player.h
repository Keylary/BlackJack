#pragma once
#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
    Player(const std::string& name = "");

    // показывает, хочет ли игрок продолжать брать карты
    bool isHitting() const override;

    // объ€вл€ет, что игрок победил
    void win() const;

    // объ€вл€ет, что игрок проиграл
    void lose() const;

    // объ€вл€ет ничью
    void push() const;
};
