#include <iostream>
#include <vector>

void print(std::vector<std::vector<int>>& vec) {
    for(auto& m : vec) {
        for(auto& n : m)
            std::cout << n << "\t";
        std::cout << "\n";
    }
}

/*
    Lis[i] stores the longest increasing subsequence that ends at index i.
    For each element in nums we check the Lis from 0...i-1. 
    If the tail of the Lis element is less than current element then we append our element to it.
    Hence Lis[i] will be Lis[j] + 1 if it is greater than the value already present.
*/

// Can be used to get the length as well the sequence
int lengthOfLIS(std::vector<int>&& nums) {
    int size = nums.size();
    std::vector<std::vector<int>> lis(size);
    lis[0].push_back(nums[0]);
    int index = 0;
    
    for(int i = 1; i < size; ++i) {
        print(lis);
        for(int j = 0; j < i; ++j) {
            if(nums[i] > nums[j] && (lis[j].size() + 1 > lis[i].size()))
                lis[i] = lis[j];
        }
        lis[i].push_back(nums[i]);
        if(lis[i].size() > lis[index].size())
            index = i;
    }
    print(lis);
    return lis[index].size();
}


// Only length
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        
        std::vector<int> lis(size);
        lis[0] = 1;
        int max_length = 1;
        
        for(int i = 1; i < size; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j] && (lis[j] + 1 > lis[i]))
                    lis[i] = lis[j];
            }
            ++lis[i];
            if(lis[i] > max_length)
                max_length = lis[i];
        }
        
        return max_length;
    }
};


int main(int argc, char **argv)
{
	std::cout << lengthOfLIS({1,3,6,7,9,4,10,5,6}) << "\n";
	return 0;
}

/*
 1,3,6,7,9,4,10,5,6

lis

1
1       3
1       3       6
1       3       6       7
1       3       6       7       9
1       3       4
1       3       6       7       9       10
1       3       4       5
1       3       4       5       6

*/

