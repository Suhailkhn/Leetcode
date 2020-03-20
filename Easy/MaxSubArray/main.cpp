#include <stdio.h>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int max_so_far{nums[0]};
        int max_ending_here{nums[0]};
        
        for(int i = 1; i < size; ++i) {
            max_ending_here += nums[i];
            max_ending_here = max_ending_here > nums[i] ? max_ending_here : nums[i];
            max_so_far = max_ending_here > max_so_far ? max_ending_here : max_so_far;
        }
        
        return max_so_far;
        
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
