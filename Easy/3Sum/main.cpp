#include <iostream>
#include <vector>
#include <unordered_set>
#include <array>
#include <algorithm>

    std::vector<std::vector<int>> result;
    std::unordered_multiset<int> values;
    std::unordered_set<int> scanned_values;
    
    void twoSum(std::vector<int> nums, int num ,int start_index, int end_index, int value) {
        int first_num;
        int num_to_find, i{start_index};
        std::vector<int> triplet;
        
        while(start_index < end_index) {
            first_num = nums[start_index];
            num_to_find = value - first_num;
            
            std::cout << "\n\nValues\n";
            for(auto& c : values)
                std::cout << c << "\t";
            std::cout << "\n\n";
            
            if(values.find(num_to_find) != values.end()) {
                
                auto it = nums.begin() + start_index + 1;
                
                if(std::find(it, nums.end(), num_to_find) == nums.end()) {
                    ++start_index;
                    continue;
                }
            
                std::array<int, 3> temp {num, first_num, num_to_find};
                std::sort(temp.begin(), temp.end());
                
                triplet.emplace_back(temp[0]);
                triplet.emplace_back(temp[1]);
                triplet.emplace_back(temp[2]);
                
                if(std::find(result.begin(), result.end(), triplet) == result.end() || result.size() == 0)
                    result.emplace_back(triplet);
                triplet.clear();
            }
            
            ++start_index;
        }
        
        auto remove_element = values.find(nums[i]);
        if(remove_element != values.end()) {
            values.erase(remove_element);
        }
        
        scanned_values.insert(nums[i-1]);
    }
    
    
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int size = nums.size();
        int num;
        
        for(int i = 1; i < size; ++i) {
            values.insert(nums[i]);
        }
        
        for(int i = 0; i < size-2; ++i) {
            if(scanned_values.find(nums[i]) == scanned_values.end()) {
                num = nums[i];
                twoSum(nums, num, i+1, size, -num);
            }
        }
        
        return result;
    }


int main(int argc, char **argv)
{
	std::vector<int> arr {3,0,3,2,-4,0,-3,2,2,0,-1,-5};
    auto sum = threeSum(arr);
    
    std::cout << "Size:\t" << sum.size() << '\n';
    
    std::cout << "RESULT\n";
    for(auto& c : sum) {
        for(auto& x : c) {
            std::cout << x << "\t";
        }
        std::cout << "\n";
    }
    
    std::cout << "Values\n";
    for(auto& c : values)
        std::cout << c << "\t";
    std::cout << "\n";
    
    std::cout << "Scanned Values\n";
    for(auto& c : scanned_values)
        std::cout << c << "\t";
    std::cout << "\n";
}
