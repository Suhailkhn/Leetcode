#include <stdio.h>

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int length = nums.size();
        std::unordered_map<int, int> num_to_count;
        
        // FInd count of each number
        for(auto& num : nums) {
            if(num_to_count.find(num) == num_to_count.end()) {
                num_to_count[num] = 1;
            } else {
                ++num_to_count[num];
            }
        }
        
        // Find degree of the array
        int degree = 0;
        for(auto& ele : num_to_count) {
            if(ele.second > degree)
                degree = ele.second;
        }
        
        int window_length {INT32_MAX};
        int low {0}, high {0};
        int current_degree {0};
        num_to_count.clear();
        
        while(high < length) {
            // Expand Window to the right to get a subarray that satisfies
            while(current_degree < degree && high < length) {
                if(num_to_count.find(nums[high]) == num_to_count.end())
                    num_to_count[nums[high]] = 1;
                else
                    ++num_to_count[nums[high]];
                
                if(num_to_count[nums[high]] > current_degree)
                    ++current_degree;
                
                ++high;
            }
            
            // Shrink the above Window from the left to remove unnecessary elements from window
            while(low < high && current_degree == degree) {
                if(num_to_count[nums[low]] == current_degree) {
                    --current_degree;
                }
                --num_to_count[nums[low]];
                if(num_to_count[nums[low]] == 0) {
                    auto it = num_to_count.find(nums[low]);
                    num_to_count.erase(it);
                }
                ++low;
            }
            
            window_length = (high - low + 1) < window_length ? high - low + 1 : window_length;
        }
        
        return window_length;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
