#include <iostream>
#include <vector>
#include <string>
//#include "Reader.h"

int linearSearch(std::vector<std::string>& data, int id, std::string_view target){
  int index = data.size()-1-id;
  if ( index < 0)
  {
      return -1;
  }
  
  if (data[index] == target){
    return index;
  }
  id++;
  return linearSearch(data,id,target);
}


int main(){
    std::vector<std::string> data {"1.1", "2.2", "3.3", "4.4"};
    std::string target {"7.7"};
    int result = linearSearch(data,0,target);
    if (result != -1)
    {
        std::cout << "Element " << target << " found at index: " << result << std::endl;
    } else {
        std::cout << "element not found" << std::endl;
    }
    
}