#include "Player.h"
#include <iostream>

Player::Player()
{
    name = "";
    HP = 0;
    x = 4;
    y = 4;
    maxHP = 100;
    isAlive = true;
}
Player::~Player()
{
    //dtor
}
void Player::setName(string n)
{
    name = n;
}
string Player::getName()
{
    return name;
}
void Player::setHP(int n)
{
    HP = n;
}
int Player::getHP()
{
    return HP;
}
void Player::setX(int i)
{
    x = i;
}
void Player::setY(int j)
{
    y = j;
}
int Player::getX()
{
    return x;
}
int Player::getY()
{
    return y;
}
void Player::setGold(int g)
{
    gold = g;
}
int Player::getGold()
{
    return gold;
}

// adds item to inventory
void Player::AddItem(Item item)
{
	inventory.push_back(item);
}
