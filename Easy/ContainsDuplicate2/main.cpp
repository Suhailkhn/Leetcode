#include <iostream>
#include <vector>

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        int last_ele = nums.size() - 1;
        for(int i = 0, j = k; i <= last_ele - k; i++, j++) {
            if(nums.at(i) == nums.at(j))
                return true;
        }
        return false;
    }

int main(int argc, char **argv)
{
    std::vector<int> mynums {1,2,3,1};
	std::cout << std::boolalpha << containsNearbyDuplicate(mynums, 3);
}
