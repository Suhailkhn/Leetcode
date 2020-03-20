#include <vector>
#include <iostream>

int removeDuplicates(std::vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }
    
    int current_num = nums[0];
    int current_num_count = 1;
    int current_index = 0;
    int length = nums.size();
    
    for(int i = 1; i < length; ++i) {
        if(nums[i] == current_num) {
            if(current_num_count < 2) {
                nums[++current_index] = nums[i];
                current_num = nums[i];
                ++current_num_count;
            } else {
                continue;
            }
        } else {
            nums[++current_index] = nums[i];
            current_num = nums[i];
            current_num_count = 1;
        }
    }
    
    return current_index + 1;
}

int main()
{
    std::cout << removeDuplicates(std::vector<int>{0, 0, 1, 1, 1, 1, 2, 3, 3});
}