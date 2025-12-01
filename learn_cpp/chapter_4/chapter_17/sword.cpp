#include <iostream>
#include <array>
#include <string_view>
#include <algorithm>

struct Item
{
    std::string_view name{};
    int gold{};
};

template<std::size_t N>
void printArray(const std::array<Item,N>& arr)
{
    for (auto &&i : arr)
    {
        std::cout << "A " << i.name << " cost " << i.gold << " gold." << std::endl;
    }
    
}

int main()
{
    constexpr std::array<Item,4> arr{{
        {"sword",  5},
        {"dagger", 3},
        {"club",   2},
        {"spear",  7} }};
    //std::cout << static_cast<std::string>(17);
    std::string str {"8 j8  mB"};
    std::string noSpc {};
    std::cout << "length: " << str.length() << "::" << str.find(" ");
    for (auto &&i : str)
    {
        if (i == ' ') 
        {
            continue; 
        }
        noSpc.push_back(i);
    }
    auto str2 = std::remove(str.begin(), str.end(), ' ');
    str.erase(std::remove(str.begin(), str.end(), ' '),str.end());
    printArray(arr);
    return 0;

}