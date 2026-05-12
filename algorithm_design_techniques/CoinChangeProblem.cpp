// WRITE YOUR CODE HERE
#include <iostream>
#include <algorithm>  // Include the <algorithm> header for sorting methods like std::sort()
#include <vector>

class CoinChangeGreedy {
public:  
    void printArray(std::vector<int>& arr){
        for (auto &&i : arr)
        {
            std::cout << i << ", ";
        }
        std::cout << std::endl;
        
    }

    // int coinChange(std::vector<int>& moneyArr, int amount) {
    //     // Sort the coins in descendomg order
    //     int size {static_cast<int>(moneyArr.size())};
    //     std::cout << "Before sorting the Array: ";
    //     printArray(moneyArr);
    //     std::cout << "After sorting the Array: ";
    //     std::sort(moneyArr.begin(), moneyArr.end(), std::greater<int>());
    //     printArray(moneyArr);
        
    //     int count = 0;
    //     // Starting from the largest coin denomination
    //     for (int i = 0; (amount >= moneyArr.back()); i++) //|| i < size-1
    //     {
    //         int billQty = amount/moneyArr[i];
    //         count += billQty;
    //         amount -= (billQty*moneyArr[i]);
    //     }
        

    //     return amount == 0 ? count : -1;
    // }
    int coinChange(std::vector<int>& moneyArr, int amount){
        // Sort the coins in ascending order
        int size {static_cast<int>(moneyArr.size()) -1 };
        std::sort(moneyArr.begin(), moneyArr.end());        
        int count = 0;
        // Starting from the largest coin denomination
        for (int i = size; (amount >= moneyArr.front()); i--) //|| i < size-1
        {
            int billQty = amount/moneyArr[i];
            count += billQty;
            amount -= (billQty*moneyArr[i]);
        }
        return amount == 0 ? count : -1;
    }
};

int main() {
    std::vector<int> moneyArr {10, 20, 5, 1}; // {6, 2, 8, 4}; //{50, 10, 5, 20}; 
    int amount {57};
    CoinChangeGreedy coinCG;
    int result = coinCG.coinChange(moneyArr, amount);

    if (result != -1) {
        std::cout << "Minimum coins needed: " << result << std::endl;
    } else {
        std::cout << "The amount cannot be represented using the given denominations." << std::endl;
    }

    return 0;
}