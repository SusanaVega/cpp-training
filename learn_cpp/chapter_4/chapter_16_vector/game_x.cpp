#include <iostream>
#include <vector>
#include <string_view>
#include <cassert>
// Let’s say you’re writing a game where the player can hold 3 types of items: health potions, torches, and arrows.
// Define an unscoped enum in a namespace to identify the different types of items.
namespace items
{
    enum item_type
    {
        health_potion,
        torches,
        arrows,
        item_tot,
    };
}

int count_items(const std::vector<int>& arr)
{
    int sum_of_items{};
    for (auto i : arr)
    {
        sum_of_items += i;
    }
    return sum_of_items;
}

void printElements(const std::vector<int>& arr)
{
    for (auto &i : arr)
    {
        std::string_view item_name{};
        switch (i)
        {
        case 1:  item_name = "health potions"; break;
        case 5:  item_name = "torches"; break;
        case 10: item_name = "arrow"; break;
        default: break;
        }
        std::cout << "You have " << i << " " << item_name << std::endl;
    }
    
}


int main()
{
    // Define an std::vector to store the number of each item type the player is carrying
    std::vector<int> num_of_item(items::item_tot); 
    
    // The player should start with 1 health potion, 5 torches, and 10 arrows
    num_of_item = {1, 5, 10};
    
    // Assert to make sure the array has the correct number of initializers.
    assert(num_of_item.at(0) == 1 &&  "Element was not initialized correctly");
    assert(num_of_item.at(1) == 5 &&  "Element was not initialized correctly");
    assert(num_of_item.at(2) == 10 && "Element was not initialized correctly");
    assert(std::size(num_of_item) == items::item_tot && "Total num of items doesn't match");

    printElements(num_of_item);
    std::cout << "You have " << count_items(num_of_item) << " total items"; 
    return 0;
}