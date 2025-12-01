#include <iostream>
#include <array>
#include <string_view>
#include "Random.h"
#define MIN 80
#define MAX 120
#include <limits> // for std::numeric_limits


/*
> Step #1
Create a Potion namespace containing an enum named Type containing the potion types.
Create two std::array: an int array to hold the potion costs, and a std::string_view array to hold the potion names.
Also write a function named shop() that enumerates through the list of Potions and prints their numbers, names, and cost.
*/

/*
> Step #2
Create a Player class to store the player’s name, potion inventory, and gold.
Add the introductory and goodbye text for Roscoe’s emporium.
Get the player’s name and randomize their gold.
Use the “Random.h” file in lesson 8.15 -- Global random numbers (Random.h) to make randomization easy.
*/

/*
> Step #3
Add the ability to purchase potions, handling invalid input (treat any extraneous input as a failure). 
Print the player’s inventory after they leave. The program should be complete after this step.

Make sure you test for the following cases:
User enters an invalid potion number (e.g. ‘d’)
User enters a valid potion number but with extraneous input (e.g. 2d, 25)
*/

namespace Potion
{
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        max_potions,
    };
    constexpr std::array types { healing, mana, speed, invisibility };
    constexpr std::array<int,max_potions> cost{20,30,12,50};
    constexpr std::array<std::string_view,max_potions> name{"healing", "mana", "speed", "invisibility"};
    static_assert(std::size(types) == max_potions);  // ensure 'all' contains the correct number of enumerators
    static_assert(std::size(cost) == max_potions);
    static_assert(std::size(name) == max_potions);
}

void shop()
{
    std::cout << "\nHere is our selection for today:\n";
    for (auto &&i : Potion::types)
    {
        std::cout << i << ") " << Potion::name[i] << " costs " << Potion::cost[i] << std::endl; 
    }
    
}

int inputHandler()
{
    int errorCounter{3};
    while (errorCounter > 0)
    {
        int potionSelection{};
        std::cin >> potionSelection;
        auto x = std::cin.peek(); 
       
        if (std::cin.fail() || std::cin.peek() != '\n') 
        {
            std::cout << "That is an invalid input.  Try again: ";
            --errorCounter;
            // Clear error flags and ignore remaining bad input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (potionSelection)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 113://q
            return potionSelection;
            break;
        
        default:
            std::cout << "That is an invalid input.  Try again: ";
            --errorCounter;
             // Clear error flags and ignore remaining bad input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            //break;
        }
        
    }
    return 999;
}

class Player
{
private:
    std::string m_name {};
    int m_gold {Random::get(MIN,MAX)};
    std::array <int,Potion::max_potions> m_inventory{};
public:
    // PLayer()
    // {
    // }
    std::string getName() {return m_name;}
    void setName(std::string name) {m_name = name;}
    void setInventory (int index) {m_inventory[index]++;}
    std::array<int,Potion::max_potions> getInventory(){return m_inventory;}
    int getGold() {return m_gold;}
    void setGold(int input) {m_gold -= input;}
    void welcomeMsg ()
    {
        std::cout << "Welcome to Roscoe's potion emporium!\n" << "Enter your name: ";
        std::string inputName {};
        std::cin >> inputName;
        setName(inputName);
        //setGold();
        std::cout << "Hello, " << getName() << ", you have " << getGold() << " gold." << std::endl;
    };
    void thanksMsg()
    {
        std::cout << "\nYour inventory contains:\n";
        for (std::size_t i{}; i < m_inventory.size() ; i++)
        {
            std::cout << m_inventory[i] << "x" << "potion of " << Potion::types[i] << std::endl;   
        }
        std::cout << "You escaped with " << getGold() << " gold remaining.\n\n";
        std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n" << std::endl;
        
    }
    void purchase()
    {
        std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
        int potionSelection{inputHandler()};
        //std::cin >> potionSelection;
        if (potionSelection == 113) //q
        {
            thanksMsg();
        }
        else
        {
            setGold(Potion::cost[potionSelection]);
            std::cout << "You purchased a potion of " << Potion::types[potionSelection] << ". You have " << getGold() << " gold left.\n";
            setInventory(potionSelection);
        }
    }
};


int main() 
{
    Player player{};
    player.welcomeMsg();
    shop();
    player.purchase();
    player.thanksMsg();
    return 0;
}