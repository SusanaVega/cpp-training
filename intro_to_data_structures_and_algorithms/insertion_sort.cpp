#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>


/*
You have been provided with a CSV file containing several columns: accountNumber, firstName, lastName, and money. 
Create the method sort that takes a vector of strings and sorts the records in descending order based on the money column.
*/


// WRITE YOUR CODE HERE
std::vector<std::string> split(const std::string& str, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
    
}
/*
GIVEN SOLUTION:
void sort(std::vector<std::string>& data) {
    int n = data.size();
    for (int i = 1; i < n; i++) {
        std::string keyRow = data[i];   // entire row data
        std::vector<std::string> parts = split(keyRow, ',');
        int keyInt = std::stoi(parts[3]); // money      
        int j = i - 1;
        
        while (j >= 0 && std::stoi(split(data[j], ',')[3]) < keyInt) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = keyRow;
    }
}
*/

std::vector<std::string> sort (std::vector<std::string>& data) 
{
    //std::vector<std::string> v{};
    for (size_t i{1}; i < data.size(); i++)
    {
        std::string key = data[i];
        std::vector<std::string> CurrentKey = split(key, ',');
        int prevElement = i-1;
        std::vector<std::string> prevKey = split(data[prevElement], ',');
        //std::cout << "prevKey[3]: " << std::stod(prevKey[3]) << "  CurrentKey[3]: " << std::stod(CurrentKey[3]) << std::endl;
        
        while(prevElement >= 0 && std::stod(prevKey[3]) < std::stod(CurrentKey[3]))
        {
            //std::cout << "****test****" << std::endl;
            prevKey = split(data[prevElement], ',');
            data[prevElement+1] = data[prevElement];
            prevElement--;
            //std::cout << "prevKeyLOOP[3]: " << std::stod(prevKey[3]) << "  CurrentKeyLOOP[3]: " << std::stod(CurrentKey[3]) << std::endl;
            
        }
        data[prevElement + 1] = key;
    }
    return data;

}