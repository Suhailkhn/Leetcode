#include <stdio.h>

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        if(size == 0)
            return 0;
        else if(size == 1)
            return triangle[0][0];
        
        std::vector<int> row;
        for(int i = size - 2; i >= 0; --i) {
            for(int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j] += std::min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        
        return triangle[0][0];
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
