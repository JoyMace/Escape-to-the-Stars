#include <iostream>
#include "Baddie.h"
#include "Item.h"
#include "MapTile.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

void addItem(Item &i, vector<Item> &v);
void takeDamage(Item &i, Baddie &b, Player &p);
void heal(Item &I, Player &p, vector<Item> &v);
void attack(Baddie &b, Item &I);
void Move(Player &p, int dx, int dy);
void moveN(Player &p);
void moveS(Player &p);
void moveE(Player &p);
void moveW(Player &p);
void printInventory(vector<Item> &v);
//string Look(int l[], MapTile m[][9]);
void Action(Player &p, vector<Item> &v, MapTile m[][9]);


int main()
{   // Items
    vector<Item> Inventory;
    Item SpaceSuit("Spacesuit", "", 0, 0, 1);
    SpaceSuit.setDescription("Prevents explosive decompression in space.");
    Item Gold("Gold", "", 0, 0, 0);
    Gold.setDescription("Heavy coins with a picture of planet Earth on one side, \nand the Moon on the other.");
    Item RayGun("Ray Gun", "", 10, 0, 1);
    RayGun.setDescription("A small gun that rapidly shoots blasts of lasers.");
    Item Flashlight("Flashlight", "", 1, 0, 1);
    Flashlight.setDescription("A small electric torch. \nVery bright when turned on.");
    Item HealingPotion("Healing Potion", "", 0, 20, 10);
    HealingPotion.setDescription("Potent but rare. Use wisely.");
    Inventory.push_back(HealingPotion);
    Inventory.push_back(RayGun);

    //Baddies
    Baddie GreenAlien("Green googly-eyed Alien", 15, 1);
    //I can't figure out how to set Baddies as data members of the map tile class
    //so these are the other baddies that I created, but I can't do anything with them
//    Baddie BlueFluff("Blue Fluffy Fury", 20, 10);
//    Baddie MommaAlien("Big Green Momma", 30, 10);
//    Baddie RolyPoly("George the Giant Roly Poly", 50, 10);
    Baddie ROUS("R.O.U.S", 1000, 1000);
    //Map Tiles
    MapTile Start("You are in an Observatory. \n There are walls to the North, South, East and West.", false);
    MapTile End("\nYou enter the Final Room. \nTo the East the room opens up onto a large launch pad area!"
                "\nThis is it!", true);
    MapTile SDoor("\nYou enter the South Room. \nIt looks like someone used to sleep in here. \nThere is a bed and a closet."
                  "\nThere is a door to the North, where you came in.", false);
    MapTile NDoor("\n You enter the North Room. \nThere are scratches covering the walls and a foul smell. \nBe careful!!!", false);
    MapTile EDoor("\nYou enter the East Room. This looks more like a hallway than a room... "
                  "\nMaybe there is an exit nearby! \nThere is a door to the East...",  false);
    MapTile WDoor("\nYou enter the West Room. \nThere are empty shelves and diagrams on the walls."
                "\nEverything has been destroyed by someone... or something...!",  false);
    MapTile Death("You have been eaten by an R.O.U.S!", true);
    Death.setBaddie_on(true);
    MapTile SS("\nYou found a Spacesuit!", false); //place spacesuit on this tile
    MapTile FL("\nYou found a flashlight!", false);//place flashlight on this tile
    MapTile USS(false);//use the spacesuit on this tile
    MapTile Monster("A Big googly-eyed alien appears!", false);
    //as above, since I couldn't figure out how to set baddies on tiles, I can't use these map tiles
//    MapTile BF("A furious blue fluff appears!",false);
//    MapTile MA("Oh no! It's the Big Green Momma!", false);
//    MapTile RP("George the Giant Roly Poly looks mad...", false);
    MapTile Rodent("I didn't think they existed!", true);
    MapTile Cliff("Turn back! This is a cliff!", true);//blank tiles
    MapTile G("\nYou picked up some Gold!", false);//gold tiles

    MapTile MAP[9][9];
    MAP[4][0] = SS;
    MAP[4][1] = Monster;
    MAP[4][2] = NDoor;
    MAP[4][3] = FL;
    MAP[4][4] = Start;
    MAP[4][5] = G;
    MAP[4][6] = SDoor;
    MAP[4][7] = Monster;
    MAP[4][8] = G;
    MAP[0][4] = G;
    MAP[1][4] = Monster;
    MAP[2][4] = WDoor;
    MAP[3][4] = G;
    MAP[5][4] = G;
    MAP[6][4] = EDoor;
    MAP[7][4] = USS;
    MAP[8][4] = End;
    MAP[3][5] = Monster;
    MAP[3][3] = Monster;
    MAP[5][3] = Monster;
    MAP[5][5] = Monster;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if((i < 3 && j < 3) || (i > 5 && j < 3) || (i < 3 && j > 5) || (i > 5 && j > 5))//NO tiles
            {
               MAP[i][j] = Death;
            }
            else if ((i == 3 && (j < 3 || j > 5)) || (i == 5 && (j < 3 || j > 5)) || (i < 3 && (j == 3 || j == 5))) //death tiles
            {
                MAP[i][j] = Cliff;
            }//FIX THE DEATH TILES and MAKE GAME OVER TRUE ON THOSE TILES TOO
        }
    }

    //cout << MAP[4][4].getDescription();
    string name;
    bool GO = false;
    cout << "You wake up in a dark room." << endl;
    cout << "Your head is pounding and you have a sharp pain in your arm." << endl;
    cout << "You hear a soft voice next to you..." << endl;
    cout << "Oh good, you're awake! You've had quite a shock." << endl;
    cout << "What is your name?" << endl;
    cout << endl;
    cout << "Enter your name: " << endl;
    cin >> name;
    Player player;
    player.setHP(50);
    player.setName(name);
    player.setX(4);
    player.setY(4);
    player.setGold(0);
    cout << endl;
    cout << "Sit up, " << name << ". We've got to get out of here!" << endl;
    cout << "Check your Inventory for a Healing Potion and let's go!" << endl;
    cout << "The dome ceiling is made of glass. \nYou can see the Stars up above, calling your name." << endl;
    cout << "There are four doors to the North, South, East and West." << endl;
    cout << endl;
    cout << "There's all kinds of creepy things lurking around." << endl;
    cout << "You've got to get the heck out of here!" << endl;
    cout << "But first, find as much gold as you can!" << endl;
    cout << endl;
    cout << endl;
    cout << "***ESCAPE TO THE STARS!***" << endl;
    cout << endl;
    cout << endl;
    while (player.isAlive == true && GO == false)
    {
        Action(player, Inventory, MAP);
        int m = player.getX();
        int n = player.getY();
        cout << MAP[m][n].getDescription();
        if (MAP[m][n].gameOver == true)
        {
            GO == true;
            cout << endl << "GAME OVER" << endl;
        }
        if ((m == 4) && (n == 3))
        {
            addItem(Flashlight, Inventory);
        }
        else if ((m == 4) && (n == 0))
        {
            addItem(SpaceSuit, Inventory);
        }
        else if (((m == 3) && (n == 4)) || ( (m == 4) && (n == 5)) || ((m == 5) && (n == 4)) || ((m == 4) || (n == 8)) || ((m == 0) && (n == 4)))
        {
            Gold.setNum(Gold.getNum() + 20);
            addItem(Gold, Inventory);
        }
    }
/////DON'T FORGET TO DO THE FILE I/O!!!!!!!!!!!
    return 0;
}
void addItem(Item &i, vector<Item> &v)
{
    v.push_back(i);
    cout << endl << i.getDescription() << endl;
}
void takeDamage(Item &i, Baddie &b, Player &p)
{
    p.HP = p.HP - b.damage;
    cout << "\n The " << b.getName() << " does " << b.damage << ". You have " << p.HP << " remaining." << endl;
}
void heal(Player &p, Item &I, vector<Item> &v)//Need to figure out how to call specific item
{
    if (p.getHP() < p.maxHP)
    {
        if (I.getNum() > 0)
        {
            p.setHP(p.getHP() + I.getHealth());
        }
        else
        {
            cout << "\nYou do not have any items that will heal you!" << endl;
        }
    }
    else
    {
        cout << "\n You are at maximum HP." << endl;
    }
}
void attack(Item &I)
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
void Move(Player &p, int dx, int dy)
{
    p.setX(p.getX()+dx);
    p.setY(p.getY()+dy);
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
void printInventory(vector<Item> &v)
{
    cout << endl << endl;
    cout << "\n***** Inventory *****" << endl << endl;
    for (int i = 0; i < v.size(); i++)
        {
            cout << " * " << v[i].getName() << ", " << v[i].getNum() << endl;
        }
    cout << endl << endl << endl;
}
void Action(Player &p, vector<Item> &v, MapTile m[][9])
{
    string Choices[9] = {"\nEnter the number that matches your desired action: ", "* 1 = North", "* 2 = South", "* 3 = West",
    "* 4 = East", "* 5 = Inventory", "* 6 = Look", "* 7 = Heal", "* 8 = Attack"};
    int c;
    for (int i = 0; i < 9; i++)
    {
        cout << Choices[i] << endl;
    }
    cin >> c;
    if (c > 8)
    {
        cout << "\nYou can't do that." << endl;
        cout << "Enter a number between 1 and 8: " << endl;
        cin >> c;
    }

    else if (c == 1)//north
    {
        moveN(p);
    }
    else if (c == 2)//south
    {
        moveS(p);
    }
    else if (c == 3)//west
    {
        moveW(p);
    }
    else if (c == 4)//East
    {
        moveE(p);
    }
    else if (c == 5)//inventory
    {
        printInventory(v);
    }
    else if (c == 6)//look
    {
        cout << m[p.getX()][p.getY()].getDescription() << endl;

    }
    else if (c == 7)//heal
    {
        Item I = v[1];
        heal(I, p, v);
    }
    else if (c == 8)//attack
    {
        if (m.baddie_on == true)
        {
            Item I = v[2];
            attack(I);
        }

    }

}

