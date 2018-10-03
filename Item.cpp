#include "Item.h"

Item::Item()
{
    //ctor
}
Item::Item(string n)
{
    name = n;
    description = "";
    damage = 0;
    health = 0;
    num = 0;
}
Item::~Item()
{
    //dtor
}
Item::Item(string n, string d, int x, int h, int N)
{
    name = n;
    description = d;
    damage = x;
    health = h;
    num = N;
}
void Item::setName(string n)
{
    name = n;
}
string Item::getName()
{
    return name;
}
void Item::setDescription(string d)
{
    description = d;
}
string Item::getDescription()
{
    return description;
}
void Item::setDamage(int d)
{
    damage = d;
}
int Item::getDamage()
{
    return damage;
}
void Item::setHealth(int h)
{
    health = h;
}
int Item::getHealth()
{
    return health;
}
void Item::setNum(int num)
{
    num = num;
}
int Item::getNum()
{
    return num;
}
void Item::setMaxNum(int m)
{
    maxNum = m;
}
int Item::getMaxNum()
{
    return maxNum;
}


