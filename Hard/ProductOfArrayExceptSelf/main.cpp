#include <stdio.h>

/*
    Approach:
    What value would you store in the result vector at index i ?
    It will be the product of all values to its left (0....i-1) and right (i+1....last)
    
    An easier to understand approach will be by creating two vectors of the size of nums.
    In the first vector, for each index i, we store the product of all values to its left.
    Similarly in the second vector we store the product of all values to its right.
    So the result value at index i would be the product of values at index i in the two vectors.
    This will give you a O(n) solution for both time and space.
    
    Now lets try to shrink it down to a constant space solution
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return {};
        else if(size == 1)
            return {nums[0]};
        
        // Initialize result with 1
        std::vector<int> result(size, 1);
        
        // At each index store product of values to its left
        for(int i = 1; i < size; ++i) {
            result[i] = result[i-1]*nums[i-1];
        }
        
        // For each index, Calculate product of values to its right.
        // Multiply it with the result already present at that index
        int product_right = 1;
        for(int i = size-2; i >=0; --i) {
            product_right *= nums[i+1];
            result[i] *= product_right;
        }
        
        return result;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
