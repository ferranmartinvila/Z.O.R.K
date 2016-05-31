#ifndef _NPC_
#define _NPC_
#include"creature.h"
#include "item.h"
class npc :public creature{
public:
	virtual void Talk(const vector<string>& instruction);
	virtual void Trade(){}
	virtual void Attack();
	virtual void Move(){}
	virtual void Drop();
	virtual void Die();
	virtual void Sell(item*object);
	virtual void Buy(item*object);
public:
	//Constructor
	npc(const string& name, const string& description, unsigned int live_points, unsigned int attack = 5) :creature(name, description,live_points,attack){}
};
#endif