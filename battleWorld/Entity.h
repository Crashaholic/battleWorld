#pragma once


class Entity
{
	int level;

	int armour;

	int strength;
	int health;
	int attack;

	int intelligence;
	int magic;

	int dexterity;
	int speed;

	int luck;
	int accuracy;

public:

	int getLv();

	int getAr();

	int getSt();
	int getHp();
	int getAt();

	int getIn();
	int getMa();

	int getDe();
	int getSp();

	int getLu();
	int getAc();

	void setLv(int newLv);

	void setAr(int newAr);

	void setSt(int newSt);
	void setHp(int newHP);
	void setAt(int newAt);

	void setIn(int newIn);
	void setMa(int newMa);

	void setDe(int newDe);
	void setSp(int newSp);

	void setLu(int newLu);
	void setAc(int newAc);

} ;


//===========//
//	GETTERS	 //
//===========//


int Entity::getLv()
{
	return level;
}


int Entity::getAr()
{
	return armour;
}


int Entity::getSt()
{
	return strength;
}

int Entity::getHp()
{
	return health;
}

int Entity::getAt()
{
	return attack;
}


int Entity::getIn()
{
	return intelligence;
}

int Entity::getMa()
{
	return magic;
}




int Entity::getDe()
{
	return dexterity;
}

int Entity::getSp()
{
	return speed;
}


int Entity::getLu()
{
	return luck;
}

int Entity::getAc()
{
	return accuracy;
}

//===========//
//	SETTERS	 //
//===========//


void Entity::setLv(int newLv)
{
	level = newLv;
}



void Entity::setAr(int newAr)
{
	armour = newAr;
}



void Entity::setSt(int newSt)
{
	strength = newSt;
}

void Entity::setHp(int newHp)
{
	health = newHp;
}

void Entity::setAt(int newAt)
{
	attack = newAt;
}



void Entity::setIn(int newIn)
{
	intelligence = newIn;
}

void Entity::setMa(int newMa)
{
	magic = newMa;
}



void Entity::setDe(int newDe)
{
	dexterity = newDe;
}

void Entity::setSp(int newSp)
{
	speed = newSp;
}


void Entity::setLu(int newLu)
{
	luck = newLu;
}

void Entity::setAc(int newAc)
{
	accuracy = newAc;
}