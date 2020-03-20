#include <stdio.h>

class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int last = size - 1;
        int i{0}, j{0};
        
        while(j <= last) {
            if(nums[j] == 0) {
                swap(nums[i], nums[j]);
                ++i;
                ++j;
            } else if(nums[j] == 1) {
                ++j;
            } else {
                swap(nums[j], nums[last--]);
            }
        }
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
