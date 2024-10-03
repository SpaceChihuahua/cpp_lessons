// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

struct FPlayerInfo
{
    std::string PlayerName;
    int ClanId;
    float PlayerHealth;
    float PlayerDamage;
};

std::vector<FPlayerInfo> lobby;

bool IsNameUnique(std::string& name)
{
    FPlayerInfo Player;
    for (const auto& Player : lobby) {
        if (Player.PlayerName == name) {
            return false;
        }
    }
    return true;
}
void AddPlayer()
{
    FPlayerInfo Player;
    std::cout << "Enter Player's name:";
    std::cin >> Player.PlayerName;
    if (!IsNameUnique(Player.PlayerName))
    {
        std::cout << "Player's name must be unique! \n";
        return;
    }
       
    
    while (Player.ClanId != 0 && Player.ClanId != 1)
    {
        std::cout << "Enter Clan's ID (0 or 1):";
        std::cin >> Player.ClanId;
        if (Player.ClanId != 0 && Player.ClanId != 1)
        {
            std::cout << "Clan's ID should be either 0 or 1\n";
        }
    }
    
    std::cout << "Enter Player health:";
    std::cin >> Player.PlayerHealth;
    Player.PlayerHealth = fabs(Player.PlayerHealth);

    std::cout << "Enter Player damage:";
    std::cin >> Player.PlayerDamage;
    Player.PlayerDamage = fabs(Player.PlayerDamage);

    lobby.push_back(Player);
};

void RemovePlayer()
{
    FPlayerInfo Player;
    std::string PlayerToDelete;

    std::cout << "Enter Player's name to delete:";
    std::cin >> PlayerToDelete;
    bool PlayerFound = false;

    for (auto it = lobby.begin(); it != lobby.end();) 
    {
        if (it->PlayerName == PlayerToDelete) 
        {
            it = lobby.erase(it);
            std::cout << "Player was removed from battle"<<std::endl;
            PlayerFound = true;
        }
        else 
        {
            ++it;
        }
    }
    if (!PlayerFound)
    {
        std::cout << "Player not found \n";
    }
};

void StartBattle()
{
    float FirstClanHealth = 0;
    float FirstClanDamage = 0;
    float SecondClanDamage = 0;
    float SecondClanHealth = 0;

    for (const auto& Player : lobby)
    {
        if (Player.ClanId == 0)
        {
            FirstClanHealth += Player.PlayerHealth;
            FirstClanDamage += Player.PlayerDamage;
        }
        else
        {
            SecondClanHealth += Player.PlayerHealth;
            SecondClanDamage += Player.PlayerDamage;
        }
    }

    std::cout << "First clan has " << FirstClanHealth << " health and " << FirstClanDamage << " damage" << std::endl;
    std::cout << "Second clan has " << SecondClanHealth << " health and " << SecondClanDamage << " damage" << std::endl;

    if (FirstClanDamage >= SecondClanHealth && SecondClanDamage >= FirstClanHealth)
    {
        std::cout << "Draw!\n";
    }
    else if (FirstClanDamage >= SecondClanHealth)
    {
        std::cout << "First clan wins!\n";
    }
    else if (SecondClanDamage >= FirstClanHealth)
    {
        std::cout << "Second clan wins!\n";
    }
    else
    {
        std::cout << "Result is undefined\n";
    }
    exit;
};

int main()
{
    int command;
    while (true)
    {
    std::cout << "Enter command (0 - add player, 1 - remove player, 2 - start battle\n";
    std::cin >> command;
        switch (command)
        {
        case 0:
            AddPlayer();
            break;
            case 1:
                RemovePlayer();
                break;
        case 2:
            StartBattle();
            break;
        default:
            std::cout << "Unknown command\n";
        }
    }
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
