#pragma once
class Equipment
{
	bool weapon = false;
	bool armor = false;

public:

	void setWeapon(bool _weapon);
	void setArmor(bool _armor);

	bool getWeapon();
	bool getArmor();

	void SelectWeapon(bool _weapon);
	void SelectArmor(bool _armor);

protected:
	int rating = 0;
	int Enhance = 0;
	int startforce = 0;
};

