#ifndef MAPTILE_H
#define MAPTILE_H

#include <string>
#include <iostream>
#include <vector>
#include "Baddie.h"
#include "Item.h"
using namespace std;

class MapTile
{
    public:
        MapTile();
        ~MapTile();
        bool gameOver;
        bool item_on;
        bool baddie_on;
        MapTile(bool);
        MapTile(string d, bool s);
        void setDescription(string s);
        string getDescription();
        void setBaddie_on(bool b);
        bool getBaddie_on();
        void setItem_on(bool I);
        bool getItem_on();

    protected:

    private:
        string description;
};

#endif // MAPTILE_H
