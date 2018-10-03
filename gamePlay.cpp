#include "Baddie.h"
#include "Item.h"
#include "MapTile.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//standalone file for functions of game Play
//holds functions that take two or more classes as parameters



void addItem(Item i, vector<Item> &v)
{
    v.push_back(i);
}
void takeDamage(Item i, Baddie b, Player p)
{
    p.HP = p.HP - b.damage;
    cout << "\n The " << b.getName() << " does " << b.damage << ". You have " << p.HP << " remaining." << endl;

}
void heal(Item I, Player p, Item Inventory[])
{
    string n = I.getName();
    if (p.HP < p.maxHP)
    {
       for (int i = 0; i < 10; i++)
       {
           string s = Inventory[i].getName();
           if (n == s)
        {
            p.HP = p.HP + I.getHealth();
        }
            else
            {
                cout << "\nYou do not have any items that will heal you!" << endl;
            }
       }

    }
    else
    {
        cout << "\n You are at maximum HP." << endl;
    }
}
void attack(Baddie b, Item I)
{
    if (b.HP > 0)
    {
        b.HP = b.HP - I.damage;
    }
    else
    {
        cout << "The " << b.getName() << " is dead." << endl;
    }
}
void Move(Player p, int dx, int dy)
{
    p.x += dx;
    p.y += dy;
}
void moveN(Player p)
{
    Move(p, 0, -1);
}
void moveS(Player p)
{
    Move(p, 0, 1);
}
void moveE(Player p)
{
    Move(p, 1, 0);
}
void moveW(Player p)
{
    Move(p, -1, 0);
}
void Look(MapTile m)
{
    cout << m.getDescription();
}
void Action(Player p, vector<Item> &v, MapTile m)
{
//    enum Choice
//    {
//    1 = North,
//    2 = South,
//    3 = East,
//    4 = West,
//    5 = Inventory,
//    6 = Look,
//    7 = Heal,
//    8 = Attack
//    };
//    Choice choice;

string Choices[8] = {"Enter the number that matches your desired action: ", "1 = North", "2 = South", "3 = East", "4 = West" "5 = Inventory", "6 = Look", "7 = Heal", "8 = Attack"};
int i;
    for (int i = 0; i < 8; i++)
    {
        cout << Choices[i] << endl;
    }
    cin >> i;
    if (i == 1)
    {
        moveN(p);
    }
    else if (i == 2)
    {
        moveS(p);
    }
    else if (i == 3)
    {
        moveE(p);
    }
    else if (i == 4)
    {
        moveW(p);
    }
    else if (i == 5)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << v[i].getName() << endl;
        }
    }
    else if (i == 6)
    {
        Look(m);
    }
    else if (i == 7)
    {
        //heal(Item I, Player p, Item Inventory[]);
        //doesn't need to have an item passed to it,
        //instead write heal differently to ask to choose an item
        //then use that item's attributes to heal
    }
    else if (i == 8)
    {
        if (m.bad == true)
        {
            //same as with heal
            //need to rewrite those functions to look in inventory
            //chose item
            //then attack
            //attack(Baddie b, Item I);
        }

    }
    else
    {
        cout << "\nYou can't do that." << endl;
    }
}
//to add items to inventory
//also need to set up baddies differently (see Piazza)
//
