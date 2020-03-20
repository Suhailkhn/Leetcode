#include <iostream>
#include <vector>
#include <set>

   std::vector<double> medianSlidingWindow(std::vector<int>&& nums, int k) {
        std::vector<double> result;
        int size = nums.size();
        std::multiset<double> sorted_nums;
        
        // Create the sorted first window
        for(int i = 0; i < k; ++i) {
            sorted_nums.insert(nums[i]);
        }
        
        // Reach median of the window
        // If median is average of two elements then it_median is the first of the two elements
        std::multiset<double>::iterator it_median = sorted_nums.begin();
        for(int i = 1; i < (k+1)/2; ++i)
            ++it_median;
        
        // Result of first window
        k % 2 == 0 ? result.emplace_back((*it_median + *std::next(it_median, 1)) / 2.0) : result.emplace_back(*it_median);
        
        // Remaining windows
        for(int i = 0, j = k; j < size; ++i, ++j) {
            sorted_nums.insert(nums[j]);        // Insert new number in its sorted place.
            if(nums[i] == *it_median) {         // Number going out of the window is the median
                auto it = it_median;
                if(nums[j] < *it_median) {      // Number was inserted to the left of the median
                    --it_median;                // Hence left part of median has become bigger than right
                } else {
                    ++it_median;
                }
                sorted_nums.erase(it);
            } else {
                auto it = sorted_nums.find(nums[i]);
                sorted_nums.erase(it);
                
                // If insertion and deletion were performed on the same side of median,
                // Then no change is required since the two parts remain equal length
                if(nums[i] < *it_median && nums[j] >= *it_median)
                    ++it_median;
                else if(nums[i] > *it_median && nums[j] < *it_median)
                    --it_median;
            }
            
            k % 2 == 0 ? result.emplace_back((*it_median + *std::next(it_median, 1)) / 2.0) : result.emplace_back(*it_median);
        }
        
        return result;
    }

int main(int argc, char **argv)
{
	auto vec = medianSlidingWindow({2147483647,1,2,3,4,5,6,7,2147483647}, 2);
    
    for(auto& e : vec) {
        std::cout << "\t" << e;
    }
    std::cout << "\n";
	return 0;
}
