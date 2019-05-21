#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;

class Player
{
	// Player is playable character
	// Player Has HP, a life status (bool isAlive), an Inventory of Items
	// Player has a location and a name

public:
	Player();
	~Player();
	int HP;
	int maxHP = 100;
	int x;
	int y;
	bool isAlive;

	void setName(string);
	string getName();
	void setHP(int HP);
	int getHP();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();



	// Player can move, can heal, can attack
	void Move(Player &p, int dx, int dy);
	void Heal(int health);
	void Attack(Baddie baddie);

protected:

private:
	string name;
};

#endif // PLAYER_H
