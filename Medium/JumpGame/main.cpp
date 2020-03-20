#include <stdio.h>

class Solution {
public:
    bool can_reach(std::vector<int>& nums, int to, int from) {
        // Base Case
        if(from == 0) {
            if(nums[from] >= to-from)   
                return true;
            else
                return false;
        }
        
        if(nums[from] >= to-from)                       // Can you make the jump index from => index to
            return can_reach(nums, from, from - 1);     // Check if you can even reach index from
        else
            return can_reach(nums, to, from - 1);
        
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        
        if(size == 1)
            return true;
        
        return can_reach(nums, size-1, size-2);
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}

// Keep track of the maximum index you can reach
bool canJump(int A[], int n) {
    int i = 0;
    for (int reach = 0; i < n && i <= reach; ++i)
        reach = max(i + A[i], reach);
    return i == n;
}