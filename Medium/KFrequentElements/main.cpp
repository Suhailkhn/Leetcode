#include <stdio.h>

#include <map>
#include <unordered_map>
#include <utility>
#include <functional>

static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        std::unordered_map<int, int> num_to_count;
        std::multimap<int, int, std::greater<int>> count_to_num;
        
        for(auto& n : nums) {
            if(num_to_count.find(n) != num_to_count.end())
                ++num_to_count[n];
            else
                num_to_count[n] = 1;
        }
        
        for(auto& item : num_to_count) {
            count_to_num.insert(std::make_pair(item.second, item.first));
        }
        
        std::vector<int> result;
        int i{0};
        for(auto& n : count_to_num) {
            if(i >= k)
                break;
            result.emplace_back(n.second);
            ++i;
        }
        
        return result;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
