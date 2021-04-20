#pragma once

#include "Equipment.h"

class Weapon : public Equipment
{
	bool mainWeapon;
	bool assistance;
	bool forcesoul;
	bool shield;
	bool emblem;

public:
	void setMainWeapon(bool _mainWeapon);
	void setAssistance(bool _assistance);
	void setForcesoul(bool _forcesoul);
	void setShield(bool _shield);
	void setEmblem(bool _emblem);
};

