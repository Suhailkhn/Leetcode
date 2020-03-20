#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
	std::vector<int> numbers {1,2,3,4,5,6,7};
    //std::rotate(numbers.begin(), numbers.begin() + numbers.size() - 3 ,numbers.end());
    std::rotate(numbers.rbegin(), numbers.rbegin() + 3, numbers.rend());
    for(auto& n : numbers)
        std::cout << n << "\t";
    std::cout << "\n";
	return 0;
}
