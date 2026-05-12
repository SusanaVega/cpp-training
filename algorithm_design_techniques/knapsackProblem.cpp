#include <iostream>
#include <vector>
#include <algorithm>


struct Item
{
    double weight;
    double value;
    Item(double w, double v):
        weight(w), value(v){}
};

bool compare(Item a, Item b) {
    return a.value/a.weight > b.value/b.weight;
}

double maximizeValue(std::vector<Item>& items, double capacity){
    int n = static_cast<int>(items.size());
    // std::cout << "Before sort:" << std::endl;
    // for (auto &&i : items)
    // {
    //     std::cout << "Value: " << i.value << ", Weight: " << i.weight << ", Ratio: " << i.value/i.weight << std::endl;
    // }
    std::sort(items.begin(), items.end(), compare);
    // std::cout << "\nAfter sort:" << std::endl;
    // for (auto &&i : items)
    // {
    //     std::cout << "Value: " << i.value << ", Weight: " << i.weight << ", Ratio: " << i.value/i.weight << std::endl;
    // }

    double totVal{};
    for (int i = 0; i < n; i++)
    {
        if (capacity - items[i].weight > 0){
            totVal += items[i].value;
            capacity -= items[i].weight;
        }
        else{
            totVal += (capacity/items[i].weight) * items[i].value;
            capacity -= (capacity/items[i].weight) * items[i].weight;
            
        }

        
    }
    

    return totVal;
}




int main(){
    //{weight, value}
    std::vector<Item> items {{10,60},{20,100},{30,120}}; //{{30,10},{34,38},{15,84}}
    double result = maximizeValue(items,50);
    std::cout << "Total value: " << result << std::endl;
    return 0;
}