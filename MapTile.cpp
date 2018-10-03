#include "MapTile.h"

MapTile::MapTile()
{
    //ctor
}

MapTile::~MapTile()
{
    //dtor
}
MapTile::MapTile(bool status)
{
    description = "None";
    gameOver = status;
    item = false;

}
MapTile::MapTile(string d, bool s)
{
    description = d;
    gameOver = s;
    item = false;

}
MapTile::MapTile(string d, bool s)
{
    description = d;
    gameOver = s;
}
void MapTile::setDescription(string S)
{
    description = S;
}
string MapTile::getDescription()
{
    return description;
}
void MapTile::setBaddie_on(bool b)
{
    baddie_on = b;
}
bool MapTile::getBaddie_on()
{
    return baddie_on;
}
void MapTile::setItem_on(bool I)
{
    item_on = I;
}
bool MapTile::getItem_on()
{
    return item_on;
}

