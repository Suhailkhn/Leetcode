#include <stdio.h>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i{0};
        int size = matrix.size();
        
        if(size == 0)
            return false;
        
        int size_row = matrix[0].size();
        
        if(size_row == 0)
            return false;
        
        std::vector<int> rows_to_check;
        
        for(auto& vec : matrix) {
            if(vec[0] <= target && target <= vec[size_row-1])
                rows_to_check.push_back(i);
            ++i;
        }
        
        for(auto& row : rows_to_check) {
            if(std::binary_search(matrix[row].begin(), matrix[row].end(), target))
                return true;
        }
        
        return false;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
