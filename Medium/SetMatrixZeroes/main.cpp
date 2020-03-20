#include <stdio.h>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        
        std::vector<int> rows_to_set(rows, 0);
        std::vector<int> columns_to_set(columns, 0);
        
        // Find the rows and columns we have to set to 0
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < columns; ++j) {
                if(matrix[i][j] == 0) {
                    columns_to_set[j] = 1;
                    rows_to_set[i] = 1;
                }
            }
        }
        
        // Set the desired rows to 0 
        for(int i = 0; i < rows; ++i) {
            if(rows_to_set[i] == 1) {
                matrix[i].assign(columns, 0);
            }
        }
        
        // Set the desired columns to 0 
        for(int j = 0; j < columns; ++j) {
            if(columns_to_set[j] == 1) {
                for(auto& row : matrix) {
                    row[j] = 0;
                }
            }
        }
    }
};


int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
