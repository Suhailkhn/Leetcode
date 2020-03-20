#include <iostream>
#include <string>
#include <unordered_map>

/*
    Similar approach to minimum window substring.
    First expand to the right. Then shrink from left.

    Store count of each unique character in the window 
    as well as no. of unique chars
    
    when no of distinct chars exceeds k, record current window.
    Now shrink from left till no of distinct chars is back to k.
    
    Repeat
 */

    int lengthOfLongestSubstringKDistinct(std::string &&s, int k) {
        int length = s.length();
        int no_of_distinct_chars {0};           // Distinct chars in current window
        int low {0}, high {0};
        std::unordered_map<char, int> char_count;
        int result[] = {-1, low, high};         // window length and extents
        
        while(high < length) {
            if(char_count.find(s[high]) == char_count.end() ||
                                        char_count[s[high]] == 0) {
                char_count[s[high]] = 1;
                ++no_of_distinct_chars;
            } else {
                ++char_count[s[high]];
            }
            
            if(no_of_distinct_chars <= k && high - low + 1 > result[0]) {
                result[0] = high - low + 1;
                result[1] = low;
                result[2] = high;
            }
            
            if(no_of_distinct_chars <= k)
                goto NEXT;
            
            // Shrinking phase
            char removed_char;
            while(no_of_distinct_chars > k) {
                removed_char = s[low];
                ++low;
                --char_count[removed_char];
                
                if(char_count[removed_char] == 0)
                    --no_of_distinct_chars;
            }
            
            NEXT:
            ++high;
        }
        
        result[0] == -1 ? 0 : result[0];
    }

int main(int argc, char **argv)
{
	std::cout << lengthOfLongestSubstringKDistinct("WORLD", 4) << "\n";
	return 0;
}
