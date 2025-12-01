#ifndef MONSTERGAME_H
#define MONSTERGAME_H
// Declare a struct that represents your monster.
// The monster should have a type that can be one of the following: an ogre, a dragon, an orc, a giant spider, or a slime.
// Each individual monster should also have a name (use a std::string), as well as an amount of health that represents how much damage they can take before they die.
// Write a function named printMonster() that prints out all of the struct’s members
enum class Monster
{
    ogre,
    dragon,
    orc,
    giant_spider,
    slime,
};

struct MonsterStruct
{
    Monster monster;
    std::string monsterName;
    int monsterHealth;
};

// This is the content of the .h file, which is where the declarations go
void printMonster(MonsterStruct& printStruct); // function prototype for monsterGame.h

#endif