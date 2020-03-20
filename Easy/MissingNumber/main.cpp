#include <stdio.h>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> space(size + 1);
        
        for(auto& n : nums) {
            space[n] = 1;
        }
        
        int i{0};
        for(auto& n : space) {
            if(n == 0)
                break;
            ++i;
        }
        
        return i;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        long nums_sum = std::accumulate(nums.begin(), nums.end(), 0);
        long sum = size * (size + 1) / 2;
        
        return sum - nums_sum;
    }
};

/*
 class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        long long total = n * (n - 1) / 2;
        
        long long sum = 0;
        for (int n: nums)
            sum += n;
        
        return total - sum;
    }
};
 * /


int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
