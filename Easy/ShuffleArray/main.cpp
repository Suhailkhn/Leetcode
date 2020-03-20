#include <stdio.h>

#include <random>

static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();

class Solution {
public:
    std::vector<int> numbers;
    
    Solution(vector<int> nums) {
        numbers = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return numbers;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::vector<int> clone {numbers};
        
        std::random_device rd;
        std::mt19937 g(rd());
 
        std::shuffle(clone.begin(), clone.end(), g);
        //std::random_shuffle(clone.begin(), clone.end());

        return clone;
    }
};


int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}

/*
    class Solution:
    def __init__(self, nums):
        self.array = nums
        self.original = list(nums)

    def reset(self):
        self.array = self.original
        self.original = list(self.original)
        return self.array

    def shuffle(self):
        for i in range(len(self.array)):
            swap_idx = random.randrange(i, len(self.array))
            self.array[i], self.array[swap_idx] = self.array[swap_idx], self.array[i]
        return self.array
*/