#include <iostream>
#include <set>
#include <vector>

bool main(int argc, char **argv)
{
	std::set<int> numbers;
    
    std::vector<int> vec {2,4,5,6,7,4,3,2};
    
    for(auto& n : vec) {
        if(numbers.find(n) != numbers.end())
            return true;
        else {
            numbers.insert(n);
        }
    }
     return false;
}
