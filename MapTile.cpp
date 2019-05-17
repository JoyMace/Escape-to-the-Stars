#include "MapTile.h"

MapTile::MapTile()
{
    //ctor
}

MapTile::~MapTile()
{
    //dtor
}

// Make a map tile 
MapTile::MapTile(bool status)
{
    description = "None";
    gameOver = status;
    item_on = false;

}

// Make a map tile with description
MapTile::MapTile(string d, bool s)
{
    description = d;
    gameOver = s;
    item_on = false;
}

// Set Description of Map tile
void MapTile::setDescription(string S)
{
    description = S;
}

// Get Description of Map tile
string MapTile::getDescription()
{
    return description;
}

// Is Baddie on Map tile
// This will need to be changed as Map Tiles will need to be linked lists
// Any items or Baddies will need to be held in the linked list as strings
// So a bool telling whether there is a baddie is probably the wrong way to go
// Instead, we should have a method that looks for the properties of a map tile
// and in fact, this whole idea may be unnecessary depending on the rest of the code hahahaha
void MapTile::setBaddie_on(bool b)
{
    baddie_on = b;
}

// Is baddie on map tile
bool MapTile::getBaddie_on()
{
    return baddie_on;
}

// Set whether item is on map tile
// Same as above, string name of item is a better approach
void MapTile::setItem_on(bool I)
{
    item_on = I;
}

// Get whether item is on map tile
bool MapTile::getItem_on()
{
    return item_on;
}

