#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;
//Weapon, Consumable, Items
//these are items that are found on the map
//and some will be needed to complete the game
//some items will heal damage, some will inflict damage
//The methods for these are not yet written but they will necessarily contain if/else
//statements and for/while loops since HP can max out or be totally depleted
//and certain items will be consumed and removed from inventory.
class Item
{
    public:
        Item();
        int damage;
        int health;
        int num;
        int maxNum;
        Item(string);
        Item(string name, string description, int damage, int health, int num);
        ~Item();
        void setName(string n);
        string getName();
        void setDescription(string d);
        string getDescription();
        void setDamage(int d);
        int getDamage();
        void setHealth(int h);
        int getHealth();
        void setNum(int num);
        int getNum();
        void setMaxNum(int m);
        int getMaxNum();

    protected:

    private:
        string name;
        string description;



};

#endif // ITEM_H
