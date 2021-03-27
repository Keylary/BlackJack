#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(const string& name) :
    GenericPlayer(name)
{}


bool Player::isHitting() const
{
    cout << m_name << ", do you want a hit? (Y/N): ";
    char response;
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void Player::win() const
{
    cout << m_name << " wins.\n";
}

void Player::lose() const
{
    cout << m_name << " loses.\n";
}

void Player::push() const
{
    cout << m_name << " pushes.\n";
}