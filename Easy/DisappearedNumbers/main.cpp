#include <stdio.h>

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::vector<int> result;
        
        int size = nums.size();
        if(size == 0)
            return result;
        
        std::unordered_set<int> numbers;
        for(auto& n : nums) {
            if(numbers.find(n) == numbers.end())
                numbers.insert(n);
        }
        
        for(int i = 1; i <= size; ++i) {
            if(numbers.find(i) == numbers.end())
                result.emplace_back(i);
        }
        
        return result;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
