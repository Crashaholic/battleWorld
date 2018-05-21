#pragma once

//TODO: MAKE EFFECTIVE STATS
class Entity
{
	int level;
	unsigned int xp;

	int armour;

	int strength;
	int health;
	int attack;

	int intelligence;
	int magic;
	int maxMagic;

	int dexterity;
	int speed;

	int luck;
	int accuracy;

public:

	int getLv();
	unsigned int getXp();

	int getSt();
	int getHp();
	int getAr();
	int getAt();

	int getIn();
	int getMa();
	int getMaxMa();

	int getDe();
	int getSp();
	int getLk();
	int getAc();

	void setLv(int newLv);
	void setXp(int newXp);

	void setAr(int newAr);

	void setSt(int newSt);
	void setHp(int newHP);
	void setAt(int newAt);

	void setIn(int newIn);
	void setMa(int newMa);
	void forceSetMa(int newMa);
	void setMaxMa(int newMaxMa);

	void setDe(int newDe);
	void setSp(int newSp);

	void setLk(int newLk);
	void setAc(int newAc);

} ;


//===========//
//	GETTERS	 //
//===========//


int Entity::getLv()
{
	return level;
}

unsigned int Entity::getXp()
{
	return xp;
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

int Entity::getMaxMa()
{
	return maxMagic;
}



int Entity::getDe()
{
	return dexterity;
}

int Entity::getSp()
{
	return speed;
}


int Entity::getLk()
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

void Entity::setXp(int newXp)
{
	xp = newXp;
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
	if (newMa < maxMagic) {
		magic = newMa;
	}
	else {
		magic = maxMagic;
	}
}

void Entity::forceSetMa(int newMa) {
	magic = newMa;
}

void Entity::setMaxMa(int newMaxMa)
{
	maxMagic = newMaxMa;
}



void Entity::setDe(int newDe)
{
	dexterity = newDe;
}

void Entity::setSp(int newSp)
{
	speed = newSp;
}


void Entity::setLk(int newLk)
{
	luck = newLk;
}

void Entity::setAc(int newAc)
{
	accuracy = newAc;
}