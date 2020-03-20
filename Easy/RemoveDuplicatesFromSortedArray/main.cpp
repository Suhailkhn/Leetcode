#include <stdio.h>

int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) {
        return 0;
    }
    
    int current_num = nums[0];
    int current_index = 0;
    int length = nums.size();
    
    for(int i = 1; i < length; ++i) {
        if(nums[i] == current_num)
            continue;
        
        nums[++current_index] = nums[i];
        current_num = nums[i];
    }
    
    return current_index + 1;
}

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
