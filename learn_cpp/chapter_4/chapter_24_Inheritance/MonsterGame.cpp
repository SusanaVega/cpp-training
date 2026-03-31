#include <iostream>
#include <string>
#include "/home/jorge/git/cpp-training/learn_cpp/chapter_4/Chapter_8/Random.h"

// Our program is going to consist of 3 classes: a Creature class, a Player class, and a Monster class. Player and Monster both inherit from Creature.

//  a) First create the Creature class. Creatures have 5 attributes: 
//      A name (std::string), 
//      a symbol (a char), 
//      an amount of health (int), 
//      the amount of damage they do per attack (int), 
//      and the amount of gold they are carrying (int)

//  Implement these as class members. 
//      Write a full set of getters (a get function for each member)
//      void reduceHealth(int) reduces the Creature’s health by an integer amount. 
//      bool isDead() returns true when the Creature’s health is 0 or less. 
//      void addGold(int) adds gold to the Creature.

class Creature
{
protected:
    /* data */
    std::string m_name {};
    char m_a {};
    int m_health {};
    int m_damage {};
    int m_gold {};
public:
    Creature(std::string_view name, char a, int health, int damage, int gold)
    : m_name{name}, m_a{a}, m_health {health}, m_damage {damage}, m_gold{gold}
    {

    }
    const std::string& getName() const {return m_name;}
    char getSymbol() const {return m_a;}
    int getHealth() const {return m_health;}
    int getDamage() const {return m_damage;}
    int getGold() const {return m_gold;}

    void reduceHealth(int harmQty) {m_health -= harmQty;}
    bool isDead() {return m_health <= 0 ? true : false;}
    void addGold(int goldQty) {m_gold += goldQty;}
};

//  b) Now we’re going to create the Player class. 
//  The Player class inherits from Creature. Player has one additional member, the player’s level, which starts at 1. 
//  The player has a custom name (entered by the user), uses symbol ‘@’, has 10 health, does 1 damage to start, and has no gold. 
//  Write a function called levelUp() that increases the player’s level and damage by 1. 
//  Also write a getter for the level member. 
//  Finally, write a function called hasWon() that returns true if the player has reached level 20.
class Player: public Creature
{
private:
    int m_level {1};
public:
    Player()//(std::string_view name, char a = '@', int health = 10, int damage = 1, int gold = 0)
    : Creature ("", '@', 10, 1, 0)//Creature(name, a, health, damage, gold)
    {
        inputName();
        std::cout << "Welcome, " << m_name << "." << std::endl;
        std::cout << "You have " << m_health << " health and are carrying " << m_gold << " gold." << std::endl;
        
    }
    void setPlayerName(std::string_view name) {m_name = name;}
    int getLevel() const {return m_level;}
    void inputName()
    {
        std::cout << "Enter your name: ";
        std::string inputName {};
        std::cin >> inputName;
        setPlayerName (inputName);
    }
    void levelUp ()
    {
        m_damage += 1;
        m_level += 1;
    }
    bool hasWon()
    {
        return m_level == 20 ? true : false;
    }

    //attackMonster()
};
// c) Next up is the Monster class. Monster also inherits from Creature. Monsters have no non-inherited member variables.
// First, write an empty Monster class inheriting from Creature, and then add an enum inside the Monster class named Type that contains enumerators for the 3 monsters

// d) Each Monster type will have a different name, symbol, starting health, gold, and damage. Here is a table of stats for each monster Type:

// Next step is to write a Monster constructor, so we can create monsters. The Monster constructor should take a Type enum as a parameter, 
// and then create a Monster with the appropriate stats for that kind of monster.
// There are a number of different ways to implement this (some better, some worse).
// However in this case, because all of our monster attributes are predefined (not random or customized per creature), we can use a lookup table.
// Our lookup table will be a C-style array of Creature, where indexing the array with a Type will return the appropriate Creature for that Type.
// Since this Creature table is specific to Monster, we can define it inside the Monster class as static inline Creature monsterData[] { }, initialized with our Creature elements.

// e) Finally, add a static function to Monster named getRandomMonster()
// This function should pick a random number from 0 to max_types-1 and return a monster (by value)
// with that Type (you’ll need to static_cast the int to a Type to pass it to the Monster constructor).
class Monster: public Creature
{
public:
    enum MonsterType
    {
        dragon,
        orc,
        slime,
        max_types,
    };
    static MonsterType getRandomMonster()
    {
        return static_cast<MonsterType>(Random::get(0,max_types-1));
    }

    Monster(MonsterType monsterType)
    : Creature(monsterData[monsterType])
    {

    }
    //attackPlayer() 

private:
    static inline Creature monsterData[] {
        {"dragon", 'D', 20, 4, 100},
        {"orc",    'o', 4,  2, 25},
        {"slime",  's', 1,  1, 10} 
        };
    static_assert(std::size(monsterData) == max_types);

};


// f) We’re finally set to write our game logic!

// Here are the rules for the game:

// The player encounters one randomly generated monster at a time.
// For each monster, the player has two choices: (R)un or (F)ight.
// If the player decides to Run, they have a 50% chance of escaping.
// If the player escapes, they move to the next encounter with no ill effects.
// If the player does not escape, the monster gets a free attack, and the player chooses their next action.
// If the player chooses to fight, the player attacks first. The monster’s health is reduced by the player’s damage.
// If the monster dies, the player takes any gold the monster is carrying. The player also levels up, increasing their level and damage by 1.
// If the monster does not die, the monster attacks the player back. The player’s health is reduced by the monster’s damage.
// The game ends when the player has died (loss) or reached level 20 (win)
// If the player dies, the game should tell the player what level they were and how much gold they had.
// If the player wins, the game should tell the player they won, and how much gold they had

//attackMonster() handles the player attacking the monster, including leveling up.

void attackMonster(Monster& monster, Player& player)
{
    monster.reduceHealth(player.getDamage());
    std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage." << std::endl;
    std::cout << "TEST:monster's health: " << monster.getHealth() << std::endl;

}

// attackPlayer() handles the monster attacking the player.
void attackPlayer(Monster& monster, Player& player)
{
    player.reduceHealth(monster.getDamage());
    std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage." << std::endl;
    std::cout << "TEST:player's health: " << player.getHealth() << std::endl;

}

//fightMonster() handles the fight between the Player and a single Monster, including asking the player what they want to do, handling the run or fight cases.
void fightMonster(Monster& monster, Player& player)
{
    std::cout << "(R)un or (F)ight: ";
    char runFight {};
    std::cin >> runFight;
    if (runFight == 'F')
    {
        attackMonster(monster, player);
    }
    else
    {
        if (Random::get(0,1)) // if 1 scape
        {
            std::cout << "You successfully fled." << std::endl;
        }
        else
        {
            std::cout << "You failed to flee." << std::endl;
            std::cout << "TEST: Monster Attack" << std::endl;
            attackPlayer(monster, player);
        }
        

    }
}


int main()
{
    //a) b)
    //Creature o{ "orc", 'o', 4, 2, 10 };
    //o.addGold(5);
    //o.reduceHealth(1);
    //std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n";
    // std::cout << "Enter your name: ";
    // std::string inputName{};
    // std::cin >> inputName;
    
    // c)
    //Player player{};

    // d)
    // Monster m{ Monster::MonsterType::orc };
    // std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

    //Create a player
    Player player{};
    Monster m{ Monster::getRandomMonster() };
    std::cout << "You have encountered a " << m.getName() << std::endl;
    while (player.getHealth() > 0 || player.getLevel() == 20)
    {
        fightMonster(m, player);
        if (m.isDead())
        {
            player.addGold(m.getGold());
            player.levelUp();
            std::cout << "You killed the " << m.getName() << std::endl;
            std::cout << "You are now level " << player.getLevel() << std::endl;
            std::cout << "You found " << m.getGold() << std::endl;
            player.addGold(m.getGold());
            m = Monster::getRandomMonster();
            std::cout << "You have encountered a " << m.getName() << std::endl;

        }
        else
        {
            attackPlayer(m,player);
        }
        if (player.isDead())
        {
            std::cout << " You died at level " << player.getLevel() << " and with " << player.getGold() << " gold." << std::endl;
            std::cout << "Too bad you can’t take it with you!" << std::endl;
            break;
        }
    }
    if (!player.isDead()) {
        std::cout << "You won and with " << player.getGold() << " gold." << std::endl;
    }
    return 0;
}