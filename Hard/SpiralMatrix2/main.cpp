#include <iostream>
#include <vector>

    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> result(n, std::vector<int>(n,0));
        
        enum State {GOING_RIGHT, GOING_DOWN, GOING_LEFT, GOING_UP};
        State direction = GOING_RIGHT;
    
        int rows_low {0}, rows_high {n};
        int columns_low {0}, columns_high {n};
        int i{0}, j{0};
        
        //int max_num = n*n;
        int curr_num = 1;
    
        while(rows_low < rows_high && columns_low < columns_high) {
            result[i][j] = curr_num++;
        
            switch(direction) {
                case GOING_RIGHT:
                {
                    if(j == columns_high - 1) {         // Have processed the last element in the row. Change direction.
                        direction = GOING_DOWN;
                        ++i;
                        ++rows_low;                     // When we come up, don't reach this row since it is finished
                    }
                    else
                        ++j;                            // Keep going right
                    break;
                }
            
                case GOING_DOWN:
                {
                    if(i == rows_high - 1) {
                        direction = GOING_LEFT;
                        --j;
                        --columns_high;
                    } else
                        ++i;
                    break;
                }
            
                case GOING_LEFT:
                {
                    if(j == columns_low) {
                        direction = GOING_UP;
                        --i;
                        --rows_high;
                    } else
                        --j;
                    break;
                }
            
                case GOING_UP:
                {
                    if(i == rows_low) {
                        direction = GOING_RIGHT;
                        ++j;
                        ++columns_low;
                    } else
                        --i;
                    break;
                }
            }
        }
    
        return result;
    }

int main(int argc, char **argv)
{
	auto vec = generateMatrix(4);
    for(auto& m : vec) {
        for(auto& n : m) {
            std::cout << n << "\t";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
	return 0;
}
