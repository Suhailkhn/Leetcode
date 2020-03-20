#include <stdio.h>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        int size = nums.size();
        if(size == 0)
            return 0;
        else if(size == 1)
            return 1;
        
        int i{0}, j{0};
        int longest{0};
        int curr_longest{1};
        
        while(i < size) {
            while(j < size - 1 && (nums[j+1] - nums[j] == 1 || nums[j+1] == nums[j])) {
                if(nums[j+1] != nums[j])
                    ++curr_longest;
                ++j;
            }
            if(curr_longest > longest)
                longest = curr_longest;
            curr_longest = 1;
            i = j+1;
            ++j;
        }
        
        return longest;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}

// O(n) using hash table

class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> num_set = new HashSet<Integer>();
        for (int num : nums) {
            num_set.add(num);
        }

        int longestStreak = 0;

        for (int num : num_set) {
            if (!num_set.contains(num-1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.contains(currentNum+1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
}