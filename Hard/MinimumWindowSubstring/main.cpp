#include <iostream>
#include <string>
#include <unordered_map>

    std::string minWindow(std::string s, std::string t) {
        if(s.length() == 0 || t.length() == 0)
            return "";
        
        // Count of each unique character in t
        std::unordered_map<char, int> char_count_t;
        for(auto& c : t) {
            if(char_count_t.find(c) == char_count_t.end())
                char_count_t[c] = 1;
            else
                ++char_count_t[c];
        }
        
        // The number of unique characters required in any window in s
        // with their desired frequency.
        // aka the no. of conditions that a desirable window should satisfy.
        // eg. 'A' should be present 3 times, 'B' should be present 2 times, 'C' should be present once, etc.
        int chars_required = char_count_t.size();
        
        // No. of conditions currently satisfied by the window.
        int chars_satisfied {0};
        
        std::unordered_map<char, int> window_char_count;
        
        int low {0}, high {0};              // Window extents
        int result[] = {INT32_MAX, low, high};       // window length and extents
        char removed_char;
        
        while(high < s.length()) {
            // Add current char to window
            if(window_char_count.find(s[high]) == window_char_count.end())
                window_char_count[s[high]] = 1;
            else
                ++window_char_count[s[high]];
            
            if(char_count_t.find(s[high]) != char_count_t.end() && window_char_count[s[high]] == char_count_t[s[high]])
                ++chars_satisfied;
            
            // Shrink window from the left till it is still desirable
            while(low <= high && chars_satisfied == chars_required) {
                if(result[0] > high - low + 1) {       // Found a new low
                    result[0] = high - low + 1;
                    result[1] = low;
                    result[2] = high;
                }
                
                removed_char = s[low];
                ++low;
                --window_char_count[removed_char];
                
                // Character removed is there in t. Check if its frequency is still desirable.
                if(char_count_t.find(removed_char) != char_count_t.end() &&
                   window_char_count[removed_char] < char_count_t[removed_char])
                        --chars_satisfied;
            }
            
            ++high;
        }
        
        return result[0] == INT32_MAX ? "" : s.substr(result[1], result[0]);
    }

int main(int argc, char **argv)
{
	std::cout << minWindow("ADOBECODEBANC", "ABC") << "\n";
	return 0;
}
