#include <stdio.h>

class Solution {
public:
    int b_search(vector<int>& nums, int low, int high, int target) {
        int mid;
        
        while(low <= high) {
            mid = (low + high)/2;
            
            if(target < nums[mid])
                high = mid - 1;
            else if(target > nums[mid])
                low = mid + 1;
            else
                return mid;
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        
        if(size == 0)
            return -1;
        else if(size == 1) {
            if(nums[0] == target)
                return 0;
            else
                return -1;
        }
        
        
        int index_greatest_el{0};
        while(index_greatest_el < size - 1 && nums[index_greatest_el + 1] > nums[index_greatest_el]) {
            ++index_greatest_el;
        }
        
        int index = b_search(nums, 0, index_greatest_el, target);
        if(index >= 0)
            return index;
            
        index = b_search(nums, index_greatest_el + 1, size - 1, target);
        if(index >= 0)
            return index;
        
        return -1;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}


int __binsearch(vector<int> nums, int lo, int hi, int val)
    {
        while (lo <= hi) {
            int mid = (lo + hi)/2;
            if (val == nums[mid]) return mid;
            
            /* If nums[lo...mid] is sorted */
            if (nums[lo] <= nums[mid]) {
                if (val >= nums[lo] && val <= nums[mid])
                    hi = mid-1;
                else
                    lo = mid+1;
            } else {

                /* If nums[lo..mid] is not sorted, then nums[mid... hi] */
                if (val >= nums[mid] && val <= nums[hi])
                    lo = mid+1;
                else
                    hi = mid-1;
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return __binsearch(nums, 0, nums.size()-1, target);
    }