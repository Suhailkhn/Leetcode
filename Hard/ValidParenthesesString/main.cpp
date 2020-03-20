#include <iostream>
#include <string>
#include <unordered_map>

/*

The idea is pretty simple: We traverse the string and push in opening brackets and pop closing brackets.
Since we just have to tell whether the entire string is valid or not,
we don't need to use an actual stack to push in indices of opening brackets;
we can just keep count of the opening brackets.
When we encounter ')' instead of popping the stack, we just decrement count.

When we encounter a '*' then there are three paths we can go and hence we use recursion here:
1) Assume that it is '('. Hence increment count of opening brackets and move ahead aka recurse.
2) Assume it is empty i.e "". Do nothing and just move ahead.
3) Assume that it is ')'. Hence decrement count of opening brackets and move ahead

Each recursive function tells us that if we reach an index of the string with a specific number of
opening brackets, will the string be valid in the end.      
If any of the 3 routes return true then the string is valid.

There can be multiple ways via which you can reach a particular index 
with the same no. of opening brackets.
This will lead to a long chain of repeated recursive function calls from that index.
So if we store the results of these functions i.e memoization, then we don't have to do duplicate work
and our program will run much faster since we can directly use the result. 
In my case the runtime went from 308ms to 4ms!

So we have to store that if we come to an index with a specific number of opening braces 
what will be the result in the end. i.e (index, count_braces) -> true/false

In C++, you can't use std::pair as a key in unordered containers since they are not hashable.
So we build a string in a specific way to serve as a key.

*/



class Solution {
public:
    bool recursiveVaild(string& s, int start_index, int last_index, int no_of_open_braces, 
                        std::unordered_map<std::string, bool>& cache) {
        
        std::string key = std::to_string(start_index) + "|" + std::to_string(no_of_open_braces);
        if(cache.find(key) != cache.end())
            return cache[key];
        
        while(start_index <= last_index && s[start_index] != '*') {
            if(s[start_index] == '(') {
                ++no_of_open_braces;
            } else {
                if(no_of_open_braces > 0)
                    --no_of_open_braces;
                else
                    return false;
            }
            ++start_index;
        }
        
        // Base case : String has finished
        if(start_index > last_index) {
            if(no_of_open_braces == 0)          // no opening braces left
                return true;
            else
                return false;
        }
        
        cache[key] = recursiveVaild(s, start_index + 1, last_index, no_of_open_braces + 1, cache)   // Consider * as ( and move ahead
                || recursiveVaild(s, start_index + 1, last_index, no_of_open_braces, cache)         // Consider * as "" and move ahead
                || (no_of_open_braces > 0 ? recursiveVaild(s, start_index + 1, last_index, no_of_open_braces - 1, cache) : false);
                                            // Consider * as ) and move ahead
        return cache[key];
    }
    
    bool checkValidString(string s) {
        int size = s.length();
        std::unordered_map<std::string, bool> cache;
        return recursiveVaild(s, 0, size-1, 0, cache);
    }
};


/*
    Without caching
    
    bool recursiveVaild(const std::string& s, int start_index, int last_index, int no_of_open_braces) {
        while(start_index <= last_index && s[start_index] != '*') {
            if(s[start_index] == '(') {
                ++no_of_open_braces;
            } else {
                if(no_of_open_braces > 0)
                    --no_of_open_braces;
                else
                    return false;
            }
            ++start_index;
        }
        
        if(start_index > last_index) {
            if(no_of_open_braces == 0)
                return true;
            else
                return false;
        }
        
        return recursiveVaild(s, start_index + 1, last_index, no_of_open_braces + 1)
            || recursiveVaild(s, start_index + 1, last_index, no_of_open_braces)
            || (no_of_open_braces > 0 ? recursiveVaild(s, start_index + 1, last_index, no_of_open_braces - 1) : false);
    }

 */
 
int main(int argc, char **argv)
{
	std::cout << checkValidString("(*)") << "\n";
	return 0;
}
