#include <stdio.h>

// Similar to Longest Valid Parentheses

class Solution {
public:
    int minAddToMakeValid(string s) {
        int i{0};
        std::vector<int> opening_braces_index;      // Stack where opening braces are pushed.
        
        // Indicates whether the brace at an index in the string has a pair.
        // Pair means a combination of opening and closing brace
        // By default no one is paired.
        std::vector<bool> found_pair(s.size(), false);
        
        // Find which brace has a pair
        for(auto& c : s) {
            if(c == '(')
                opening_braces_index.emplace_back(i);
            else if(!opening_braces_index.empty()){
                found_pair[i] = true;
                found_pair[opening_braces_index.back()] = true;
                opening_braces_index.pop_back();
            }
            ++i;   
        }
        
        int count{0};
        for(auto b : found_pair) {
            if(!b)                  // Brace is unpaired
                ++count;
        }
        
        return count;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
