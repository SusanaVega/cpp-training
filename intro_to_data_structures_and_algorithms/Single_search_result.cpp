#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "CSVreader.h"
/*
You have been provided with a CSV file containing several columns: accountNumber, firstName, lastName, and money. 
Create the method search that takes a vector of strings and a search target (also a string). 
The method should search by money. It should return the elements from the vector that contains the search target. 
If the target is not found, the method should return an empty string.
*/

/*
SOLUTION PROPOSED BY TEST:
std::string search(const std::vector<std::string>& data, const std::string& target) {
    for (const std::string& row : data) {
        std::stringstream ss(row);
        std::string item;
        std::vector<std::string> account;

        while (std::getline(ss, item, ',')) {
            account.push_back(item);
        }

        if (account.size() > 3 && account[3] == target) {
            return row; // Return the full row
        }
    }
    return ""; // Account not found
};
*/


//SOLUTION TO: return multiple search return
// std::vector<std::string> search(std::vector<std::string> data, std::string target)
// {
//     std::vector<std::string> v{};
//     for(size_t i = 0; i < data.size(); i++)
//     {
//         if(data[i].find(target) != std::string::npos)
//         {
//             v.push_back(data[i]);
//         }
//     }
//     return v;
// }


int main()
{
    std::string path {"/home/jorge/git/cpp-training/data_structures_and_algorithms/bank.csv"};
    std::string target {"3064940.01"};
    std::vector<std::string> data = CSVReader::readCSV(path);
    std::cout << "data: " << data[0][0] << std::endl;
    for (size_t i = 0; i < data.size(); i++)
    {
        // std::cout << "****TEST Begin****" << std::endl;
        // std::cout << "data[" << i <<"]: " << data[i] << std::endl;
        // std::cout << "find: " << data[i].find(target) << std::endl;
        if (data[i].find(target) != std::string::npos)
        {
            std::cout << "FOUND!!" << std::endl;
        }
        
        // std::cout << "****TEST End****" << std::endl;    
    }
    

    return 0;
}