#include <stdio.h>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        std::sort(nums.begin(), nums.end());
        return nums[size - k];
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
