// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

class IObserver {
public:
    virtual void Update(float damage) = 0;
};

class ICharacter {
public:
    virtual void Subscribe(IObserver* observer) = 0;
    virtual void Unsubscribe(IObserver* observer) = 0;
    virtual void Notify(int damage) = 0;
    virtual void ApplyDamage(float damage) = 0;
};

class Hero : public ICharacter {
private:
    std::vector<IObserver*> observers;
    int health;

public:
    Hero(int InitialHealth) : health(InitialHealth) {}

    void Subscribe(IObserver* observer) override {
        observers.push_back(observer);
    }

    void Unsubscribe(IObserver* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void Notify(int damage) override {
        for (IObserver* observer : observers) {
            observer->Update(damage);
        }
    }

    void ApplyDamage(float damage) override {
        health -= damage;
        std::cout << "Hero takes " << damage << " damage! Health left: " << health << std::endl;
        Notify(damage);
    }

    int GetHealth() const {
        return health;
    }
};

class DamageLogger : public IObserver {
public:
    void Update(float damage) override {
        std::cout << "DamageLogger: Hero took " << damage << " damage" << std::endl;
    }
};

class HealthMonitor : public IObserver {
public:
    void Update(float damage) override {
        std::cout << "HealthMonitor: Hero's health decreased by " << damage << std::endl;
    }
};

// Тестування системи
int main() {
    Hero hero(100.0f);  // Створюємо персонажа з 100 очками здоров'я

    DamageLogger logger;
    HealthMonitor monitor;

    hero.Subscribe(&logger);    // Додаємо спостерігачів
    hero.Subscribe(&monitor);

    hero.ApplyDamage(15.0f);     // Персонаж отримує шкоду
    hero.ApplyDamage(30.0f);     // Персонаж отримує ще одну шкоду

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
