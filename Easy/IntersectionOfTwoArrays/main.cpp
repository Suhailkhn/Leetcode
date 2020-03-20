#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int>& greater_vector = nums1.size() > nums2.size() ? nums1 : nums2;
        std::vector<int>& smaller_vector = nums1.size() > nums2.size() ? nums2 : nums1;
        
        std::vector<int> result;
        
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        
        int i{0}, count_smaller{0}, count_greater{0}, count{0};
        
        while(i < smaller_vector.size()) {
            count_greater = std::count(greater_vector.begin(), greater_vector.end(), smaller_vector[i]);
            count_smaller = std::count(smaller_vector.begin(), smaller_vector.end(), smaller_vector[i]);
            
            if(count_greater > 0) {
                count = count_smaller > count_greater ? count_greater : count_smaller;
                for(int j = 0; j < count; j++) {
                    //i += count_smaller;
                    result.emplace_back(smaller_vector[i]);
                }
                i += count_smaller;
            } else
                i += count_smaller;
        }
        
        return result; 
    }


int main(int argc, char **argv)
{
    std::vector<int> nums1 {9,3,7};
    std::vector<int> nums2 {6,4,1,0,0,4,4,8,7};
	auto result = intersect(nums1, nums2);
    for(auto& n : result)
        std::cout << n << "\t";
    std::cout << "\n";
	return 0;
}

//[9,3,7]
//[6,4,1,0,0,4,4,8,7]