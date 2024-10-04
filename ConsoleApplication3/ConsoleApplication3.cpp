// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Building.h"



int main()
{
    ABuilding building(40,20000);
    std::cout << "Building max age is: " << building.GetMaxAge() << " years" << std::endl;
    std::cout << "Building initial cost is: " << building.GetInitialCost() << "$" << std::endl;
    std::cin.get();

    building.ToAge(50);

    std::cout << "Building was set to age of: " << building.GetAge() << " years" << std::endl;
    std::cout << "Building cost now is: " << building.GetCost() << "$" << std::endl;

    std::cin.get();

    ABuilding Otherbuilding(35, 40000);
    std::cout << "Building max age is: " << Otherbuilding.GetMaxAge() << " years" << std::endl;
    std::cout << "Building initial cost is: " << Otherbuilding.GetInitialCost() << "$" << std::endl;
    std::cin.get();

    Otherbuilding.ToAge(100);

    std::cout << "Building was set to age of: " << Otherbuilding.GetAge() << " years" << std::endl;
    std::cout << "Building cost now is: " << Otherbuilding.GetCost() << "$" << std::endl;

    std::cin.get();
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
