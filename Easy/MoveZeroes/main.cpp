#include <iostream>
#include <vector>

    void moveZeroes(std::vector<int>& nums) {
        int i{0}, j{0}, flag{0}, temp{0};
        
        while(j < nums.size()) {
            if(flag == 0) {
                if(nums[j] != 0) {
                    ++i;
                    ++j;
                } else {
                    ++j;
                    flag = 1;
                }
            } else {
                if(nums[j] != 0) {
                    temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                    
                    ++i;
                    ++j;
                } else {
                    ++j;
                }
            }
            
        }
    }

int main(int argc, char **argv)
{
	std::vector<int> nums {2,6,0,0,5,2,1,0,8};
    moveZeroes(nums);
    for(auto& n : nums)
        std::cout << n << "\t";
    std::cout << "\n";
	return 0;
}
