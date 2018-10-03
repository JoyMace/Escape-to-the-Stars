#include "Baddie.h"

Baddie::Baddie()
{
    //ctor
}

Baddie::~Baddie()
{
    //dtor
}
Baddie::Baddie(string n, int HP, int d)
{
    name = n;
    HP = HP;
    damage = d;

}
void Baddie::setName(string s)
{
    name = s;
}
string Baddie::getName()
{
    return name;
}
void Baddie::setHP(int n)
{
    HP = n;
}
int Baddie::getHP()
{
    return HP;
}
void Baddie::setDamage(int d)
{
    damage = d;
}
int Baddie::getDamage()
{
    return damage;
}
