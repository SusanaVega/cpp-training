#include <iostream>
#include <vector>
#include <limits>


// Write a function that takes a std::vector, 
// returns a std::pair containing the indices of the elements with the min and max values in the array.

template <typename T>
size_t minFunc(const std::vector<T>& minArr)
{
    size_t lenght = minArr.size();
    T min{minArr[0]};
    size_t minIndex{0};
    for (size_t i = 0; i < lenght; i++)
    {
        if (min > minArr[i])
        {
            min = minArr[i];
            minIndex = i;
        }
    }
    return minIndex;
    
}

template <typename U>
size_t maxFunc(const std::vector<U>& maxArr)
{
    size_t lenght = maxArr.size();
    U max{maxArr[0]};
    size_t maxIndex{0};
    for (size_t i = 0; i < lenght; i++)
    {
        if (max < maxArr[i])
        {
            max = maxArr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
    
}


template <typename V>
std::pair<std::size_t,std::size_t> minMax(const std::vector<V>& myArr)
{
    std::pair<std::size_t,std::size_t> indices{};
    indices.first = minFunc(myArr);
    indices.second = maxFunc(myArr);
    //std::cout << "first: " << indices.first << "\tsecond: " << indices.second << std::endl;
    return indices;
}

template <typename V>
void printArray (const std::vector<V>& myArr)
{
    bool comma { false };
    std::cout << "With array ( ";
    for (auto i : myArr)
    {
        if (comma) 
        {
            std::cout << ", ";
        }
        std::cout << i;
        comma = true;
    }
    std::cout << "):\n";
    
}

template <typename T>
std::vector<T> vectorGen()
{
    std::cout << "Enter the numbers to add (use -1 to stop):";
    std::vector<T> v{};
    while (true)
    {
        T x{};
        std::cin >> x;

        if (!std::cin) // handle bad input
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
        if (x == -1)
        {
            break;
        }
        v.push_back(x);
    }
    
    if (v.empty())
    {
        std::cout << "you created an empty array";
    }
    return v;
}

int main()
{
    //std::vector<int> v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector<int> v1 {vectorGen<int>()};
    //v1 = vectorGen();
    printArray(v1);
    std::pair<std::size_t,std::size_t> testv1{minMax(v1)};
    // std::cout << "minIndex: " << minFunc(v1) << "\t";
    // std::cout << "maxIndex: " << maxFunc(v1) << "\t" << std::endl;
    std::cout << "The min element has index " << testv1.first << " and value " << v1.at(testv1.first) << std::endl; 
    std::cout << "The min element has index " << testv1.second << " and value " << v1.at(testv1.second) << std::endl;

    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };
    printArray (v2);
    std::pair<std::size_t,std::size_t> testv2{minMax(v2)};
    std::cout << "The min element has index " << testv2.first << " and value " << v2.at(testv2.first) << std::endl; 
    std::cout << "The min element has index " << testv2.second << " and value " << v2.at(testv2.second) << std::endl;




    return 0;
}