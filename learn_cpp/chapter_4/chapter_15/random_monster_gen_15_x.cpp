#include <iostream>
#include <string_view>
#include "Random.h"

// a) First, let’s create an scoped enumeration of monster types named MonsterType.
// Include the following monster types: Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie. 
// Add an additional maxMonsterTypes enumerator so we can count how many enumerators there are.

// enum class MonsterType
// {
//     Dragon, 
//     Goblin, 
//     Ogre, 
//     Orc, 
//     Skeleton, 
//     Troll, 
//     Vampire,
//     Zombie,
//     maxMonsterTypes,
// };

// b) Now, let’s create our Monster class. Our Monster will have 4 attributes (member variables): 
// a type (MonsterType), a name (std::string), a roar (std::string) and the number of hit points (int).

class Monster
{
    public:
        // c) enum class MonsterType is specific to Monster, so make MonsterType a nested unscoped enum 
        // inside Monster and rename it to Type.
        enum Type
            {
                dragon, 
                goblin, 
                ogre, 
                orc, 
                skeleton, 
                troll, 
                vampire,
                zombie,
                maxMonsterTypes,
            };
        // d) Create a constructor that allows you to initialize all of the member variables.
        Monster (Type monster , std::string_view name, std::string_view roar, int hit_points)
            :m_monster{monster}, m_name{name}, m_roar{roar}, m_hitPoints{hit_points}
        {       
        }
        // e) Now we want to be able to print our monster so we can validate it’s correct. 
        // Write two functions: One called getTypeString() that returns the monster’s type as a string, 
        // and one called print() that matches the output in the sample program below.
        constexpr std::string_view getTypeString() const 
        {
            switch (m_monster)
            {
            case Type::dragon:   return "dragon";   break;
            case Type::goblin:   return "goblin";   break;
            case Type::ogre:     return "ogre";     break;
            case Type::orc:      return "orc";      break;
            case Type::skeleton: return "skeleton"; break;
            case Type::troll:    return "troll";    break;
            case Type::vampire:  return "vampire";  break;
            case Type::zombie:   return "zombie";   break;          
            default:             return "???";      break;
            }
        }

        void print() const 
        {
            if (m_hitPoints > 0)
            {
                std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << "." << std::endl;
            }
            else
            {
                std::cout << m_name << " the " << getTypeString() << " is dead. " << std::endl;       
            }
        }


    private:
        Type m_monster{};
        std::string m_name{"???"};
        std::string m_roar{"???"};
        int m_hitPoints{};


};

// f) Now we can create a random monster generator. Let’s consider how our MonsterGenerator will work. 
// Ideally, we’ll ask it to give us a Monster, and it will create a random one for us. 
// Because MonsterGenerator doesn’t have any state, this is a good candidate for a namespace.
// Create a MonsterGenerator namespace. Create function within named generate(). This should return a Monster.

namespace MonsterGenerator
{
    // g) Add two more functions to the MonsterGenerator namespace. 
    // getName(int) will take a number between 0 and 5 (inclusive) and return a name of your choice.
    // getRoar(int) will also take a number between 0 and 5 (inclusive) and return a roar of your choice. 
    // Also update your generate() function to call getName(0) and getRoar(0).
    std::string_view getName(int randomName)
    {
        switch (randomName)
        {
        case 0:  return "Moka";  break;
        case 1:  return "Lola";  break;
        case 2:  return "Shary"; break;
        case 3:  return "Tula";  break;
        case 4:  return "Kawi";  break;
        case 5:  return "Mylo";  break;
        default: return "???";  break;
        }
    }

    std::string_view getRoar(int randomRoar)
    {
        switch (randomRoar)
        {
        case 0:  return "wawa";  break;
        case 1:  return "bubu";  break;
        case 2:  return "jiji";  break;
        case 3:  return "roar";  break;
        case 4:  return "woww";  break;
        case 5:  return "puuu";  break;
        default: return "???";  break;
        }
    }

    Monster generate()
    {
        // h) Now we’ll randomize our generated monster. 
        // Grab the “Random.h” code from 8.15 -- Global random numbers (Random.h) and save it as Random.h. 
        // Then use Random::get() to generate a random monster type, random name, random roar, 
        // and random hit points (between 1 and 100).
        return Monster
        {
            static_cast<Monster::Type>(Random::get(0,8)), 
            getName(Random::get(0,5)), 
            getRoar(Random::get(0,5)),
            Random::get(1,100)};
    }
};

int main()
{
	// Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
	// skeleton.print();

	// Monster vampire{ Monster::vampire, "Nibblez", "*hiss*", 0 };
	// vampire.print();

    Monster m{ MonsterGenerator::generate() };
	m.print();





    return 0;
}