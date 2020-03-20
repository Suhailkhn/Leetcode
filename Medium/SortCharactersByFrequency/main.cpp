#include <stdio.h>

class Solution {
public:
    string frequencySort(string s) {
        // Get count/frequency of each unique character
        std::unordered_map<char, int> char_count;
        for(auto& c : s) {
            if(char_count.find(c) == char_count.end())
                char_count[c] = 1;
            else
                ++char_count[c];
        }
        
        // Create a mapping containing the list of chars corresponding to each frequency
        // maintained in descending order of frequency
        std::map<int, std::vector<char>, std::greater<int>> count_to_chars;
        for(auto& ele : char_count) {
            count_to_chars[ele.second].emplace_back(ele.first);
        }
        
        // Append each unique character frequency no. of times
        std::string result;
        for(auto& ele : count_to_chars) {
            for(auto& character : ele.second) {
                result.append(ele.first, character);
            }
        }
        
        return result;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
