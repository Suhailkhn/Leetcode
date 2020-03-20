#include <iostream>
#include <vector>

    void rotate(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        int temp{0};
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j != i; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        std::cout << "\n\nTranspose\n\n";
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                std::cout << matrix[i][j] << "\t";
            }
            std::cout << "\n";
        }
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns/2 ; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][columns-1-j];
                matrix[i][columns-1-j] = temp;
            }
        }
        
    }

int main(int argc, char **argv)
{
	std::vector<std::vector<int>> numbers {{1,2,3},{4,5,6},{7,8,9}};
 
    std::cout << "Original matrix:\n\n";
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = 0; j < numbers[0].size(); j++) {
            std::cout << numbers[i][j] << "\t";
        }
        std::cout << "\n";
    }
   
    rotate(numbers);
    
    std::cout << "\n\nRotated matrix:\n\n";
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = 0; j < numbers[0].size(); j++) {
            std::cout << numbers[i][j] << "\t";
        }
        std::cout << "\n";
    }
}
