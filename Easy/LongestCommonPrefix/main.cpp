#include <stdio.h>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        
        std::ostringstream oss;
        oss << "";
        int i{0};
        char ele;
        size_t smallest_size{strs[0].size()};
        
        // Find length of smallest string
        for(auto& str : strs) {
            size_t str_size = str.size();
            if(str_size < smallest_size)
                smallest_size = str_size;
        }
        
        // Compare i-th element of all strings
        for(i = 0; i < smallest_size; ++i) {
            ele = strs[0][i];
            for(auto it = strs.begin() + 1; it != strs.end(); ++it) {
                if(it->at(i) != ele)
                    goto ABC;
            }
            oss << ele;
        }
        
        ABC:
        return oss.str();
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
