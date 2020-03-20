#include <iostream>
#include <string>
#include <unordered_map>

// Own. Correct. Similar approach to Minimum Window Substring
/*
    We push each character in a hash table/ hash set and expand to the right 
    until we find a repeating character x.
    When we find a repeating character, we record the length of
    the current substring not including x and update the result if needed.
    
    Then we start removing all the characters from the left until we find x
    and that point we just move one step forward.
    
    eg. abcdefc....
    We keep pushing the chars until f in a hash table since they are distinct.
    When we come to the second c, we remove all characters from the left
    until we find the first copy of c. Then we just step ahead to d.
    We don't remove the first c from the hash table since 
    we would again have to push the second c in it 
    to find the next substring of distinct chars and that would be redundant.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        if(length == 0)
            return 0;
        
        int low{0}, high{0};
        int result[] = {-1, low, high};         // Substring length and extents
        
        std::unordered_set<char> chars;
        
        char removed_char;
        
        while(high < length) {
            auto it = chars.find(s[high]);
            if(it == chars.end())
                chars.insert(s[high]);
            else {                              // Repeating character
                if(high - low > result[0]) {    // Record length and extents
                    result[0] = high - low;     
                    result[1] = low;
                    result[2] = high - 1;
                }
                
                // Shrinking phase
                while(s[high] != s[low]) {
                    removed_char = s[low];
                    it = chars.find(removed_char);
                    chars.erase(it);
                    ++low;
                }
                
                ++low;
                
            }
            ++high;
        }
        
        return high - low > result[0] ? high - low : result[0];
    }
};

// Alternate
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }


// Doesn't clear all test cases 
   int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> char_to_index;
        int length = 0;
        int current_length = 0;
        int i {0};
        
        for(auto& c : s) {
            if(char_to_index.find(c) == char_to_index.end()) {
                ++current_length;
                char_to_index[c] = i;
            } else {
                if(current_length > length)
                    length = current_length;
                
                current_length = i - char_to_index[c];

                for(int index = 0; index < char_to_index[c]; ++index) {
                    char_to_index.erase(char_to_index.find(s[index]));
                }
                
                char_to_index[c] = i;
            }
            
            ++i;
        }
        
        return length > current_length ? length : current_length;
    }



int main(int argc, char **argv)
{
    std::cout << lengthOfLongestSubstring("hRcGnC8H6mwasgN4HH6uJWljI8a5irvuODHY7A7ku4PJY2anS") << "\n";
	return 0;
}
