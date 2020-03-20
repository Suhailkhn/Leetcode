#include <iostream>
#include <string>

    std::string expand(std::string s, size_t low, size_t high) {
        auto len = s.length();
        while(low >= 0 && high < len && (s[low] == s[high])) {
            --low;
            ++high;
        }
        
        return s.substr(low+1, high - low - 1);
    }
    
    std::string longestPalindromeSubseq(std::string s) {
        int length = 0;
        int curr_length = 0;
        std::string curr_str, max_str;
        
        for(size_t i = 0; i < s.size(); ++i) {
            // Odd length
            curr_str = expand(s, i, i);
            curr_length = curr_str.length();
            if(curr_length > length) {
                length = curr_length;
                max_str = curr_str;
            }
            
            // Even length
            curr_str = expand(s, i, i+1);
            curr_length = curr_str.length();
            if(curr_length > length) {
                length = curr_length;
                max_str = curr_str;
            }
        }
        
        return max_str;
    }

int main(int argc, char **argv)
{
	std::cout << longestPalindromeSubseq("abcdasdfghjkldcba");
	return 0;
}
