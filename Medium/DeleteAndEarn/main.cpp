#include <stdio.h>

#include <unordered_map>
#include <vector>

/*
    The problem is similar to House Robber problem.
    So we convert this problem to that and solve this in a similar way
*/

static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        std::unordered_map<int,int> unique_num_to_value;    // Will give the points earned by deleting all         
                                                            // elements 'k'
        std::vector<int> unique_nums;
        
        // Store unique elements and keep their count
        for(auto& n : nums) {
            if(unique_num_to_value.find(n) == unique_num_to_value.end()) {
                unique_num_to_value[n] = 1;
                unique_nums.push_back(n);
            } else {
                ++unique_num_to_value[n];
            }
        }
        
        std::sort(unique_nums.begin(), unique_nums.end());
        
        // Total Points earned by deleting x
        for(auto& ele : unique_num_to_value) {
            ele.second = ele.first * ele.second;
        }
        
        int size_unique = unique_nums.size();
        if(size_unique == 0)
            return 0;
        
        std::vector<int> points(size_unique);       // Stores the max points obtained until index k 
                                                    // of the unique ele set
        
        points[0] = unique_num_to_value[unique_nums[0]];
        
        if(size_unique == 1)
            return points[0];
        
        if(unique_nums[1] - 1 == unique_nums[0])
            points[1] = unique_num_to_value[unique_nums[1]] > points[0] ?
                        unique_num_to_value[unique_nums[1]] : points[0];
        else
            points[1] = points[0] + unique_num_to_value[unique_nums[1]];
        
        /*
            If We want to del an element x at index i then we also have to delete x-1 and x+1 if they are present.
            $ We are storing unique elements in sorted order, so if x-1 is present, it will be present at i-1.
            $$ Then, we choose to del x if points obtained by deleting x is greater than not deleting it.
            
            We are not concerned with deleting x+1 because our points vector stores points obtained until index i.
            So if x+1 is present it will be ahead of i and hence we don't bother about it.
            It will be taken care of as we move ahead.
        */
        
        for(int i = 2; i < size_unique; ++i) {
            if(unique_nums[i] - 1 == unique_nums[i-1])      // $
                points[i] = points[i-2] + unique_num_to_value[unique_nums[i]] > points[i-1] ?       // $$
                            points[i-2] + unique_num_to_value[unique_nums[i]] : points[i-1];
            else
                points[i] = points[i-1] + unique_num_to_value[unique_nums[i]];
        }
        
        return points[size_unique-1];
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
