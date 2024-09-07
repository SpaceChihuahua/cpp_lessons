// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

float DamageTaken(float distance, float result_damage, float base_damage)
{
    if (distance > 100) 
    {
        result_damage = 0;
        std::cout << "Item is too far, so it can not damage the Hero \n";
    }
    else if (distance < 0) 
    {
        std::cout << "Invalid input, distance must be a positive value  \n";
    }
    else 
    {
        result_damage = base_damage * (1 - distance / 100);
    }
    return result_damage;
}


int main()
{
    float health;
    std::cout << "Enter hero's health: \n";
    std::cin >> health;
    
    while (health > 0)
    {
        float base_damage;
        std::cout << "Enter item's base damage: \n";
        std::cin >> base_damage;
        
        float distance;
        std::cout << "Enter distance to item: \n";
        std::cin >> distance;

        float result_damage = 0;

        result_damage = DamageTaken(distance, result_damage,  base_damage);
        health = health - result_damage;
        if (health > 0 && health < 1) 
        {
            health = 1;
        }
        else {}

        std::string impact;

        if (result_damage >= 0)
        {
            impact = "Hero was damaged for: ";
        }
        else
        {
            impact = "Hero was healed for: ";
        }
        std::cout << impact << fabs (result_damage) << std::endl;
        std::cout << "Current health: " << health << std::endl;
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
