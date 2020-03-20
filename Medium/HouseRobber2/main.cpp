#include <stdio.h>

// Apply House Robber solution twice. 
// First consider that you will rob the first house, so the last house is taken out of consideration.
// Then do the other way around. Whichever result is greater, that's your answer.

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> dp(size);
        
        if(size == 0)
            return 0;
        else if(size == 1)
            return nums[0];
        else if(size == 2)
            return nums[0] > nums[1] ? nums[0] : nums[1];
        
        int takeIt{0}, leaveIt{0};
        
        // Rob first house
        dp[0] = nums[0];
        dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        
        for(int i = 2; i < size - 1; ++i) {
            takeIt = nums[i] + dp[i-2];
            leaveIt = dp[i-1];
            dp[i] = takeIt > leaveIt ? takeIt : leaveIt;
        }
        
        int first = dp[size-2];
        
        // Rob last house i.e skip robbing the first house
        dp[0] = 0;
        dp[1] = nums[1];
        dp[2] = nums[1] > nums[2] ? nums[1] : nums[2];
        
        for(int i = 3; i < size; ++i) {
            takeIt = nums[i] + dp[i-2];
            leaveIt = dp[i-1];
            dp[i] = takeIt > leaveIt ? takeIt : leaveIt;
        }
        
        int second = dp[size-1];
        
        return first > second ? first : second;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
