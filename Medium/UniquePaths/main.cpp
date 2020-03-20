#include <stdio.h>

#include <algorithm>

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Initialize the table to 0
        // We need an extra row an coluwn at the start to make the formula applicable
        std::vector<std::vector<int>> table (m+1, std::vector<int> (n+1, 0));
        
        // You can reach point (i,j) only from (i-1,j) and (i,j-1)
        // So, the number of ways to reach (i, j) will be the addition of those two points
        for(int i = 1; i < m+1; ++i) {
            for(int j = 1; j < n+1; ++j)
                table[i][j] = std::max(table[i-1][j] + table[i][j-1], 1);
        }
        
        return table[m][n];
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
