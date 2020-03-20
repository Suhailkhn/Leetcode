#include <stdio.h>
/* Runtime O(2^n)
 
    int lps(std::string& s, int low, int high) {
        if(low > high)
            return 0;
        else if(low == high)
            return 1;
        
        if(s[low] == s[high])
            return lps(s, low+1, high-1) + 2;
        else
            return max(lps(s, low+1, high), lps(s, low, high-1));
    }
    
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        return lps(s, 0, len - 1); 
    }

 */
 
 
     int lps(std::string& s, int low, int high, std::unordered_map<std::string, int>& lookup) {
        if(low > high)
            return 0;
        else if(low == high)
            return 1;
        
        std::string key = std::to_string(low) + "|" + std::to_string(high);
        
        if(lookup.find(key) == lookup.end()) {
            if(s[low] == s[high])
                return lps(s, low+1, high-1, lookup) + 2;
            else
                return max(lps(s, low+1, high, lookup), lps(s, low, high-1, lookup));
        }
        
        return lookup[key];
    }
    
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        std::unordered_map<std::string, int> lookup;
        return lps(s, 0, len - 1, lookup); 
    }
 
int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
