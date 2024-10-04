#pragma once
#include <iostream>

class ABuilding
{
    int Id = -1;
    static int NextId;
    int MaxAge = 50;
    int InitialCost = 10000;
    int Years = 0;

    void Destroy()
    {
        std::cout << "Building with ID " << Id << " was destroyed due to reaching maximum age \n";
    }

public:
    ABuilding();

    ~ABuilding()
    {
        std::cout << "Building was destroyed due to end of times \n";
    }

    ABuilding(int _MaxAge, int _InitialCost);

    void ToAge(int _Years);

    int GetMaxAge();

    int GetInitialCost();

    int GetCost();

    int GetAge();

};