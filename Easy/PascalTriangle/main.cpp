#include <stdio.h>

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;
        std::vector<int> level;
        
        int k{0};
        for(int i = 0; i < numRows; ++i, ++k) {
            for(int j = 0; j < i; ++j) {
                if(j == 0) {
                    level.push_back(1);
                    continue;
                }
                level.emplace_back(triangle[k-1][j-1] + triangle[k-1][j]);
            }
            level.push_back(1);
            triangle.emplace_back(level);
            level.clear();
        }
        
        return triangle;
    }
};


int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
