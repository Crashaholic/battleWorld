#pragma once


class Entity
{
	int level;

	int health;
	int armour;
	int attack;
	int strength;

	int magic;
	int intelligence;

	int dexterity;
	int accuracy;
	int speed;

public:

	int getLv();

	int getHp();
	int getAr();
	int getAt();
	int getSt();

	int getMa();
	int getIn();

	int getDe();
	int getAc();
	int getSp();

	virtual void setLv(int newLv);

	void setHp(int newHP);
	void setAr(int newAr);
	void setAt(int newAt);
	void setSt(int newSt);

	void setMa(int newMa);
	void setIn(int newIn);

	void setDe(int newDe);
	void setAc(int newAc);
	void setSp(int newSp);

} ;


//===========//
//	GETTERS	 //
//===========//


int Entity::getLv()
{
	return level;
}



int Entity::getHp()
{
	return health;
}

int Entity::getAt()
{
	return attack;
}

int Entity::getAr()
{
	return armour;
}

int Entity::getSt()
{
	return strength;
}



int Entity::getMa()
{
	return magic;
}

int Entity::getIn()
{
	return intelligence;
}



int Entity::getDe()
{
	return dexterity;
}

int Entity::getAc()
{
	return accuracy;
}

int Entity::getSp()
{
	return speed;
}


//===========//
//	SETTERS	 //
//===========//


void Entity::setLv(int newLv)
{
	level = newLv;
}



void Entity::setHp(int newHp)
{
	health = newHp;
}

void Entity::setAr(int newAr)
{
	armour = newAr;
}

void Entity::setAt(int newAt)
{
	attack = newAt;
}

void Entity::setSt(int newSt)
{
	strength = newSt;
}



void Entity::setMa(int newMa)
{
	magic = newMa;
}

void Entity::setIn(int newIn)
{
	intelligence = newIn;
}



void Entity::setDe(int newDe)
{
	dexterity = newDe;
}

void Entity::setAc(int newAc)
{
	accuracy = newAc;
}

void Entity::setSp(int newSp)
{
	speed = newSp;
}

