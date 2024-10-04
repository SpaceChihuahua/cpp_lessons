#include "Building.h"

int ABuilding::NextId = 0;

ABuilding::ABuilding()
{
	Id = NextId;
	NextId++;
}

ABuilding::ABuilding(int _MaxAge, int _InitialCost)
{
	MaxAge = _MaxAge;
	InitialCost = _InitialCost;
	Id = NextId;
	NextId++;
}

void ABuilding::ToAge(int _Years)
{
	Years = _Years;
	if (Years >= MaxAge)
	{
		Destroy();
	}
}

int ABuilding::GetMaxAge()
{
	return MaxAge;
}

int ABuilding::GetInitialCost()
{
	return InitialCost;
}

int ABuilding::GetCost()
{
	if (Years >= MaxAge)
	{
		return 0;
	}
	else
	{
		return InitialCost * (MaxAge - Years) / MaxAge;
	}
}

int ABuilding::GetAge()
{
	return Years;
}








