#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

class Player
{
    public:
        Player();
        ~Player();
        int HP;
        int maxHP = 100;
        int x;
        int y;
        bool isAlive;
        int gold;
        void setName(string);
        string getName();
        void setHP(int HP);
        int getHP();
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();
        void setGold(int g);
        int getGold();
    protected:

    private:
        string name;
};

#endif // PLAYER_H
