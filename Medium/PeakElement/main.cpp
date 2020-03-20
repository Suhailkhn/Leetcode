#include <stdio.h>

public class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
}

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        
        if(size == 1 || nums[0] > nums[1])
            return 0;
        else if(nums[size - 1] > nums[size - 2])
            return size - 1;
        
        for(int i = 1; i < size - 1; ++i) {
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        }
        
        return -1;                  // To get around compiler warning
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
