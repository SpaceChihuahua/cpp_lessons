// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <memory>

class Weapon
{
public:
	virtual float GetDamage() = 0;
	virtual std::string GetName() = 0;
	virtual ~Weapon()
	{
		std::cout << "Weapon was destroyed \n";
	}
};

class Character
{
private:
	std::vector<std::unique_ptr<Weapon>> Arsenal;
	Weapon* EquippedWeapon;

public:
	Character() : EquippedWeapon(nullptr) {}

	void AddWeapon(std::unique_ptr<Weapon> weapon) 
	{
		Arsenal.push_back(std::move(weapon));
	}

	void SetWeapon(Weapon* weapon)
	{
		EquippedWeapon = weapon;
	}

	Weapon* GetWeapon() const
	{
		return EquippedWeapon;
	}

	void ShowArsenal() const {
		std::cout << "Available weapons: \n";
		for (const auto& weapon : Arsenal) {
			std::cout << "- " << weapon->GetName() << " (Damage: " << weapon->GetDamage() << std::endl;
		}
	}
	Weapon* FindWeapon(const std::string& weaponName) const {
		for (const auto& weapon : Arsenal) {
			if (weapon->GetName() == weaponName) {
				return weapon.get();
			}
		}
		std::cout << "There's no such weapon \n";
		return nullptr;
	}
};

class Melee : public Weapon 
{

	float GetDamage() override
	{
		return 25.0f;
	}
	std::string GetName()
	{
		return "Melee weapon";
	}

};

class Firearms : public Weapon
{
	float GetDamage() override
	{
		return 35.0f;
	}
	std::string GetName()
	{
		return "Firearms";
	}
};

class MagicWeapons : public Weapon
{
	float GetDamage() override
	{
		return 50.0f;
	}
	std::string GetName()
	{
		return "Magic weapon";
	}
};

int main()
{
	Character character;

	int choice = 0;
	std::cout << "Choose a weapon to add to your arsenal: 1 - add Melee, 2 - add Firearm, 3 - add magic weapon, 4 - show added weapons, 9 - next step \n";
	std::cin >> choice;

	while (choice != 9)
	{
		if (choice == 1)
		{
			character.AddWeapon(std::make_unique<Melee>());
			std::cout << "Melee weapon was added to inventory \n";
		}
		if (choice == 2)
		{
			character.AddWeapon(std::make_unique<Firearms>());
			std::cout << "Firearm was added to inventory \n";
		}
		if (choice == 3)
		{
			character.AddWeapon(std::make_unique<MagicWeapons>());
			std::cout << "Magic weapon was added to inventory \n";
		}
		if (choice == 4)
		{
			character.ShowArsenal();
		}
		std::cin >> choice;
	}
	std::cout << "Choose a weapon to equip (only one weapon can be quipped). 1 - equip melee, 2 - equip firearm, 3 - equip magic weapon, 4 - show owned and equipped weapons, 9 - exit \n";
	int SecondChoice = 0;
	std::cin >> SecondChoice;
	while (SecondChoice != 9)
	{
		if (SecondChoice == 1)
		{
			Weapon* Melee = character.FindWeapon("Melee weapon");
			if (Melee)
			{
				character.SetWeapon(Melee);
				std::cout << character.GetWeapon()->GetName() << " was equipped" << std::endl;
			}
		}
		if (SecondChoice == 2)
		{
			Weapon* Firearms = character.FindWeapon("Firearms");
			if (Firearms)
			{
				character.SetWeapon(Firearms);
				std::cout << character.GetWeapon()->GetName() << " was equipped" << std::endl;
			}
		}
		if (SecondChoice == 3)
		{
			Weapon* MagicWeapons = character.FindWeapon("Magic weapon");
			if (MagicWeapons)
			{
				character.SetWeapon(MagicWeapons);
				std::cout << character.GetWeapon()->GetName() << " was equipped" << std::endl;
			}
		}
		if (SecondChoice == 4)
		{
			character.ShowArsenal();
			if (character.GetWeapon()) 
			{
				std::cout << "Equipped weapon: " << character.GetWeapon()->GetName() << std::endl;
			}
			else 
			{
				std::cout << "No weapon equipped.\n";
			}
		}
		std::cin >> SecondChoice;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
