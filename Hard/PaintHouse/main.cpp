#include <iostream>
#include <vector>


/*
Input:
colors ->
house    10   4   6   9   7
  |       5   8   8   4   5
         12   9  10   7   8
          6  11   5   9  10

DP Table
10    4    6    9   7
 9   14   12    8   9
20   17   18   16  16
22   27   21   25  26

 */


int minCostII(std::vector<std::vector<int>> &costs) {
        std::pair<int, int> prev_level_min (INT32_MAX, -1);     // Stores the minimum value and its column index since no two adj houses
        int prev_level_smin {INT32_MAX};                        // can be of the same colour
        
        std::pair<int, int> curr_level_min (INT32_MAX, -1); 
        int curr_level_smin {INT32_MAX};
        
        int size = costs.size();
        if(size == 0)
            return 0;
        
        int columns = costs[0].size();
        
        // First row/house
        for(int j = 0; j < columns; ++j) {
            if(costs[0][j] <= prev_level_min.first) {
                prev_level_smin = prev_level_min.first;
                prev_level_min.first = costs[0][j];
                prev_level_min.second = j;
            }
            else if(costs[0][j] < prev_level_smin)
                prev_level_smin = costs[0][j];
        }
        
        int curr_sum;
        for(int i = 1; i < size; ++i) {
            for(int j = 0; j < columns; ++j) {
                if(j == prev_level_min.second)          // Minimum of previous house is of the same colour
                    curr_sum = costs[i][j] + prev_level_smin;
                else
                    curr_sum = costs[i][j] + prev_level_min.first;
                
                if(curr_sum <= curr_level_min.first) {
                    curr_level_smin = curr_level_min.first;
                    curr_level_min.first = curr_sum;
                    curr_level_min.second = j;
                }
                else if(curr_sum < curr_level_smin)
                    curr_level_smin = curr_sum;
            }
            prev_level_min = curr_level_min;
            prev_level_smin = curr_level_smin;
            
            curr_level_min = std::pair<int, int>(INT32_MAX, -1);
            curr_level_smin = INT32_MAX;
        }
        
        return prev_level_min.first;
    }

int main(int argc, char **argv)
{
	std::vector<std::vector<int>> myvec {{10, 4, 6, 9, 7},
                                         {5, 8, 8, 4, 5},
                                         {12, 9, 10, 7, 8},
                                         {6, 11, 5, 9, 10}};
    
    std::cout << minCostII(myvec) << "\n";
	return 0;
}

/*
    {10,  4,  6, 9,  7}
    { 5,  8,  8, 4,  5}
    {12,  9, 10, 7,  8}
    { 6, 11,  5, 9, 10}

 =>
    {10,  4,  6,  9,  7}
    { 9, 14, 12,  8,  9}
    {20, 17, 18, 16, 16}
    {22, 27, 21, 25, 26}
    
    Answer will be minimum value in the last level
*/