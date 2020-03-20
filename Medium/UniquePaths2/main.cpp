#include <stdio.h>

/*
        You can reach point (i,j) only from (i-1,j) and (i,j-1)
        So, the number of ways to reach (i, j) will be the addition of those two points
        But if one of them is an obstacle then the no. of ways to reach (i,j) will be 
        the ways to reach the other point
        Points unreachable are marked -1 in our table
*/

#include <algorithm>

static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // Initialize the table to 0
        // We need an extra row an coluwn at the start to make the formula applicable
        std::vector<std::vector<long int>> table (m+1, std::vector<long int> (n+1, 0));
        
        for(int i = 1; i < m+1; ++i) {
            for(int j = 1; j < n+1; ++j) {
                if(obstacleGrid[i-1][j-1] == 1) {       // Obstacle encountered
                    table[i][j] = -1;
                    continue;
                } else if(table[i-1][j] == -1 && table[i][j-1] == -1) { // Up and left are obstacles
                    table[i][j] = -1;
                    continue;
                }
                else if(table[i-1][j] == -1) {      // Only Above is an obstacle
                    if(table[i][j-1] == 0) {
                        table[i][j] = -1;
                        continue;
                    }
                    table[i][j] = table[i][j-1] > 1 ? table[i][j-1] : 1;   
                }
                else if(table[i][j-1] == -1) {      // Only Left is an obstacle
                    if(table[i-1][j] == 0) {
                        table[i][j] = -1;
                        continue;
                    }
                    table[i][j] = table[i-1][j] > 1 ? table[i-1][j] : 1;
                }
                else {
                    table[i][j] = table[i-1][j] + table[i][j-1] > 1 ? table[i-1][j] + table[i][j-1] : 1;     
                } 
            }
        }
        
        return table[m][n] > 0 ? table[m][n] : 0;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
