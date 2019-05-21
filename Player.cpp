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

void Move(Player &p, int dx, int dy)
{
	p.setX(p.getX() + dx);
	p.setY(p.getY() + dy);
}
void moveN(Player &p)
{
	Move(p, 0, -1);
}
void moveS(Player &p)
{
	Move(p, 0, 1);
}
void moveE(Player &p)
{
	Move(p, 1, 0);
}
void moveW(Player &p)
{
	Move(p, -1, 0);
}
