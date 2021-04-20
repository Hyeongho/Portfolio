#include "Equipment.h"

void Equipment::setWeapon(bool _weapon)
{
	weapon = _weapon;
}

void Equipment::setArmor(bool _armor)
{
	armor = _armor;
}

bool Equipment::getWeapon()
{
	return weapon;
}

bool Equipment::getArmor()
{
	return armor;
}

void Equipment::SelectWeapon(bool _weapon)
{
}

void Equipment::SelectArmor(bool _armor)
{
}
