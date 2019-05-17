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
		//consttructor and destructor
        MapTile();
        ~MapTile();

		// is gameOver true?
        bool gameOver;

		// Does this map tile contain an item?
        bool item_on;

		//Does this map tile hide a baddie?
        bool baddie_on;

		// two ways to make a map tile
        MapTile(bool);
        MapTile(string d, bool s);

		// Set and get description of new map tile
        void setDescription(string s);
        string getDescription();

		// Set and get  baddies on map tile
        void setBaddie_on(bool b);
        bool getBaddie_on();

		// Set and get items on map tile
        void setItem_on(bool I);
        bool getItem_on();

    protected:

    private:
        string description;
};

#endif // MAPTILE_H
