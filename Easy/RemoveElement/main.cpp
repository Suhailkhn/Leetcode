#include <stdio.h>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())
            return 0;
        
        int length = nums.size();
        int index = -1;
        
        for(int i = 0; i < length; ++i) {
            if(nums[i] != val) {
                ++index;
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
            }
        }
        
        return index + 1;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
