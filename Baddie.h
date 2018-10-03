#ifndef BADDIE_H
#define BADDIE_H
#include <string>

using namespace std;

//baddies will be created once and then placed randomly on map tiles
//They will inflict damage once discovered until either they die or the player dies
//They have 4 data members and more than 4 methods which will need loops and if/else
//statements to control how long the baddie is used/useful etc.
class Baddie
{
    public:
        Baddie();
        ~Baddie();
        int damage;
        int HP;
        Baddie(string n, int d, int HP);
        void setName(string);
        string getName();
        void setHP(int h);
        int getHP();
        void setDamage(int d);
        int getDamage();


    protected:

    private:
        string name;

};

#endif // BADDIE_H
