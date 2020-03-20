#include <stdio.h>

// We will be storing indices of the currently fresh oranges so that we can iterate only on those 
// rather than the entire grid when trying to find out if there are any new rotten oranges.
// I have flattened the array to store the index and then unpack to save time and space, 
// but for ease you can also store it as a std::pair<int, int> of (row, column).

// We simply scan each fresh orange and check if any of its neighbours are rotten.
// If yes, we have found a new rotten orange and we store its index.

// If for an iteration, after scanning through all fresh oranges we did not find a single new rotten one, 
// it means it is impossible to reach the desired condition.


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        std::unordered_set<int> fresh_orange_flatten_index;
        int width = grid[0].size();
        int rows = grid.size();
        int count_fresh {0};
        
		// Get indices of all fresh oranges
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < width; ++j) {
                if(grid[i][j] == 1) {
                    ++count_fresh;
                    fresh_orange_flatten_index.insert(i*width + j);
                }
            }
        }
        
        if(count_fresh == 0)                 // Condition already satisfied
            return 0;
        
        int newly_rotten_count {0};
        std::vector<int> newly_rotten_flat_index;
        int minutes {0};
        
        while(count_fresh > 0) {
            for(auto& flat_index : fresh_orange_flatten_index) {
                int i = flat_index / width;
                int j = flat_index % width;
                
				// Check if any neighbour is rotten
                if((i-1 >= 0 && grid[i-1][j] == 2) ||
                   (i+1 < rows && grid[i+1][j] == 2) ||
                   (j-1 >= 0 && grid[i][j-1] == 2) ||
                   (j+1 < width && grid[i][j+1] == 2))
                {
                    ++newly_rotten_count;
                    newly_rotten_flat_index.push_back(flat_index);
                }
            }
            
			// Can't progress further
            if(newly_rotten_count == 0) {
                return -1;
            }
            
			// Remove newly rotten from list of fresh oranges and update state in grid
            for(auto& flat_index : newly_rotten_flat_index) {
                auto it = fresh_orange_flatten_index.find(flat_index);
                fresh_orange_flatten_index.erase(it);
                
                int i = flat_index / width;
                int j = flat_index % width;
                grid[i][j] = 2;
            }
            
            newly_rotten_flat_index.clear();
            count_fresh -= newly_rotten_count;
            newly_rotten_count = 0;
            ++minutes;
        }
        
        return minutes;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
