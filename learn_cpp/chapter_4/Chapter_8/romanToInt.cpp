#include <map>
#include <iostream>
class Solution {
public:
    std::map<char, int> romanNumMap;
    Solution(){
        romanNumMap['I']= 1;
        romanNumMap['V']= 5;
        romanNumMap['X']= 10;
        romanNumMap['L']= 50;
        romanNumMap['C']= 100;
        romanNumMap['D']= 500;
        romanNumMap['M']= 1000;
    }
    int romanToInt(string s) {
        //string lenght
        int s_length = s.length();
        std::cout << "length: " << s_length << std::endl;
        int sum{};
        for (int i = (s_length-1);i>=0;i--){
            if (i == 0){
                auto it1 = romanNumMap.find(s[0]);
                std::cout <<"before value:" << sum << std::endl;
                sum += it1 -> second;
                std::cout <<"Last value:" << sum << std::endl;
                break;
            }
            else {            
                //Find the inger value of the roman number in romanNumMap
                auto it1 = romanNumMap.find(s[i]);
                auto it2 = romanNumMap.find(s[i-1]);
                int currentValue = it1 -> second;
                int nextValue = it2 -> second; 
                //sum+= value;
                std::cout <<"currentValue: " << currentValue << std::endl;
                std::cout <<"nextValue: " << nextValue << std::endl;
                //if current value is grater to the next value: T = current - next F = current + next
                if (nextValue < currentValue){
                    sum = sum + (currentValue - nextValue);
                    i--; // move to the other value
                    std::cout <<"sum1: " << sum << std::endl;
                    //sum += sum;
                }
                else{
                    sum = sum + (currentValue + nextValue);
                    std::cout <<"sum2: " << sum << std::endl;
                    i--;
                    //sum += sum;    
                }
            }    
        } 

        std::cout <<"sum: " << sum << std::endl;
        return sum;
    }
};