#include <iostream>
#include <vector>

    std::vector<int> searchRange(std::vector<int>&& nums, int target) {
        int size = nums.size();
        int l = 0, r{size - 1}, mid;
        int index;
        bool found{false};
        
        if(size == 1 && nums[0] == target)
            return {0,0};
        
        while(l <= r) {
            mid = (l+r)/2;
            if(nums[mid] > target) {
                r = mid - 1;
            } else if(nums[mid] < target) {
                l = mid + 1;
            } else {
                found = true;
                index = mid;
                break;
            }
        }
        
        if(!found)
            return {-1,-1};
        
        l = index - 1;
        while(nums[l] == target && l >= 0) {
            --l;
        }
        
        r = index + 1;
        while(nums[r] == target && r < size) {
            ++r;
        }
        
        return {l + 1, r - 1};
        
    }

int main(int argc, char **argv)
{
    auto vec = searchRange({1,2,3,4,4,4,4,5,6,6,7,8,8}, 4);
	std::cout << vec[0] << "\t" << vec[1] << "\n";
}
