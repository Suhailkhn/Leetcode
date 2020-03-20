#include <vector>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int curr_processed_num {NULL};
        int largest {0}, curr_area;
        int size = heights.size();
        int expand_left{0}, expand_right{0};
        
        for(int i = 0; i < size; ++i) {
            if(heights[i] == curr_processed_num)
                continue;
            
            expand_left = 0;
            expand_right = 0;
            
            for(int j = i+1; j < size && heights[j] >= heights[i]; ++j)
                ++expand_right;
            
            for(int j = i-1; j >= 0 && heights[j] >= heights[i]; --j)
                ++expand_left;
            
            curr_area = heights[i] * (expand_left + 1 + expand_right);
            
            if(curr_area > largest)
                largest = curr_area;
            
            curr_processed_num = heights[i];
        }
        
        return largest;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
