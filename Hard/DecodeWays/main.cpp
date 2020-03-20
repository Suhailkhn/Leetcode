#include <iostream>
#include <string>
#include <vector>

TOP - DOWN

    int decode(std::string& s, int last_index, std::vector<int>& cache) {
        if(last_index >= 0 && cache[last_index] != -1)
            return cache[last_index];
    
        // Base conditions
        if(last_index == -1) {
            cache[0] = 1;
            cache[1] = 1;
            return 1;
        }
        else if(last_index == 0 && s[last_index] != '0') {
            cache[0] = 1;
            return 1;
        }
    
        // Only double digits is allowed
        if(s[last_index] - '0' == 0) {
            if(s[last_index - 1] - '0' == 0 || s[last_index - 1] - '0' > 2)
                return 0;
            else {
                if(last_index >= 2 && cache[last_index-2] == -1) {
                    cache[last_index-2] = decode(s, last_index-2, cache);
                    return cache[last_index-2];
                }
                return decode(s, last_index-2, cache);
            }
        }
        // Only single digit is allowed
        else if(s[last_index-1] == '0' || std::stoi(s.substr(last_index-1, 2)) > 26) {
            if(last_index >= 1 && cache[last_index-1] == -1) {
                cache[last_index-1] = decode(s, last_index - 1, cache);
                return cache[last_index-1];
            }
            return decode(s, last_index - 1, cache);
        }
        else {
            cache[last_index] = decode(s, last_index - 1, cache) + decode(s, last_index - 2, cache);
            return cache[last_index];
        }
    }

int numDecodings(std::string&& s) {
    size_t len = s.length();
    if(len == 0 || s[0] == '0')
        return 0;
    std::vector<int> cache(len, -1);
    return decode(s, len-1, cache);
}

int main(int argc, char **argv)
{
	std::cout << numDecodings("10") << '\n';
	return 0;
}

/*
"9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253"
Without memoization
Output: 3981312   
Time: 000:08:156

With memoization
Output: 3981312
Time elapsed: 000:00:172

*/


public class Solution {
        public int numDecodings(String s) {
            if(s == null || s.length() == 0){
                return 0;
            }
            int n = s.length();
            int[] dp = new int[n+1];
            dp[0] = 1;
            dp[1] = s.charAt(0) != '0' ? 1 : 0;

            for(int i = 2; i <= n; i++){
                int first = Integer.valueOf(s.substring(i-1,i));
                int second = Integer.valueOf(s.substring(i-2,i));
                if(first >= 1 && first <= 9){
                    dp[i] += dp[i-1];
                }
                if(second >= 10 && second <= 26){
                    dp[i] += dp[i-2];
                }

            }
            return dp[n];

        }


public int numDecodings(String s) {
    if(s==null || s.length()==0 || s.charAt(0)=='0')
        return 0;
    if(s.length()==1)
        return 1;
 
    int[] dp = new int[s.length()];    
    dp[0]=1;
    if(Integer.parseInt(s.substring(0,2))>26){
        if(s.charAt(1)!='0'){
            dp[1]=1;
        }else{
            dp[1]=0;
        }
    }else{
        if(s.charAt(1)!='0'){
            dp[1]=2;
        }else{
            dp[1]=1;
        }
    }
 
    for(int i=2; i<s.length(); i++){
        if(s.charAt(i)!='0'){
            dp[i]+=dp[i-1];
        }
 
        int val = Integer.parseInt(s.substring(i-1, i+1));
        if(val<=26 && val >=10){
            dp[i]+=dp[i-2];
        }
    }
 
    return dp[s.length()-1];
}



public static int decodeWays(String s) {// s 是 non-empty

		int i = 0;
		int[] dp = new int[s.length()];// dp[i]表示，以s[i]为结尾的字符串的解码方式的【总数】，解不出来用0表示
		int totleNumber = 0;

		for (i = 0; i < s.length(); ++i) {
			// 依次填充dp[i]
			if (s.charAt(i) == '0') {
				if (i == 1) {
					dp[i] = ((s.charAt(i - 1) == '1' || s.charAt(i - 1) == '2') ? 1 : 0);
				}
				else if (i > 1) {
					dp[i] = ((s.charAt(i - 1) == '1' || s.charAt(i - 1) == '2') ? dp[i - 2] : 0);
				} 
			} else {// s[i]非0
				if(i == 0)
					dp[i] = 1;
				else if(i == 1)
					dp[i] = dp[i - 1] + ((s.charAt(i - 1) == '1' || (s.charAt(i - 1) == '2' && s.charAt(i) <= '6'))?1:0);
				else
					dp[i] = dp[i - 1] + ((s.charAt(i - 1) == '1' || (s.charAt(i - 1) == '2' && s.charAt(i) <= '6'))?dp[i - 2]:0);
			}
		}
		return dp[s.length() - 1];

	}



// A Dynamic Programming based function to count decodings 
int countDecodingDP(char *digits, int n) 
{ 
    int count[n+1]; // A table to store results of subproblems 
    count[0] = 1; 
    count[1] = 1; 
  
    for (int i = 2; i <= n; i++) 
    { 
        count[i] = 0; 
  
        // If the last digit is not 0, then last digit must add to 
        // the number of words 
        if (digits[i-1] > '0') 
            count[i] = count[i-1]; 
  
        // If second last digit is smaller than 2 and last digit is 
        // smaller than 7, then last two digits form a valid character 
        if (digits[i-2] == '1' || (digits[i-2] == '2' && digits[i-1] < '7') ) 
            count[i] += count[i-2]; 
    } 
    return count[n]; 
}