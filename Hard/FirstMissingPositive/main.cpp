#include <iostream>
#include <vector>
#include <unordered_set>

int firstMissingPositive(std::vector<int>&& nums) {
        std::unordered_set<int> nums_above_zero;
        
        if(nums.size() == 0)
            return 1;
        
        int min{INT32_MAX};
        for(auto& n : nums) {
            if(n > 0 && nums_above_zero.find(n) == nums_above_zero.end()) {
                nums_above_zero.insert(n);
                min = min < n ? min : n;
            }
        }
        
        if(min != 1)
            return 1;
        
        int missing_positive {-1};
        
        for(auto& n : nums) {
            if(n <= 0)
                continue;
            
            if(INT32_MAX - n > 0 && nums_above_zero.find(n+1) == nums_above_zero.end()) {
                if(missing_positive == -1)
                    missing_positive = n+1;
                else
                    missing_positive = missing_positive < n+1 ? missing_positive : n+1;
            }
        }
        
        return missing_positive;
    }

int main(int argc, char **argv)
{
	std::cout << firstMissingPositive({0,1,2}) << '\n';
	return 0;
}
