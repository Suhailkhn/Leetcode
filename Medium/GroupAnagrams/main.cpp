#include <stdio.h>

class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> result;
        
        int size = strs.size();
        
        if(size == 0)
            return result;
        else if(size == 1)
            return {strs};
        
        // Maps each anagram to the indices it occurs
        std::unordered_map<std::string, std::vector<int>> anagram_to_indices;
        
        // Generate the map
        int i {0};
        for(auto s : strs) {
            std::sort(s.begin(), s.end());
            anagram_to_indices[s].push_back(i);
            ++i;
        }
        
        for(auto& anagram: anagram_to_indices) {
            result.push_back({});
            for(auto& index: anagram.second) {
                result.back().push_back(strs[index]);
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
