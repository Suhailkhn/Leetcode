#include <iostream>
#include <vector>
#include <string>
#include <map>

    // Tell me if I break the string at the supplied index using any word, will I succeed in the end
    bool recursive_word_break(std::string& s, int length, size_t start_index,
                              std::map<char, std::vector<std::string>>& eligible_strings, std::vector<int>& cache) {
        if(eligible_strings.find(s[start_index]) == eligible_strings.end()) {       // No words present to break the string at this index
            cache[start_index] = 0;
            return false;
        }
        
        for(auto& word : eligible_strings[s[start_index]]) {    // For all the strings that start with the same letter as at the index
            if(start_index + word.size() - 1 >= length)         // Word is longer than the string remaining
                continue;
            if(s.compare(start_index, word.size(), word) == 0) {    // word matches the corresponding part of the string
                if(start_index + word.size() - 1 == length-1) {     // String completed
                    cache[start_index] = 1;
                    return true;
                }
                else {
                    // Only recurse if the next starting index has not been processed yet otherwise use its result
                    if(cache[start_index + word.size()] == -1 && recursive_word_break(s, length, start_index + word.size(), eligible_strings, cache)) {
                        cache[start_index + word.size()] = 1;
                        cache[start_index] = 1;
                        return true;
                    } else if(cache[start_index + word.size()] == 1) {
                        cache[start_index] = 1;
                        return true;
                    }
                }
            }
        }
        
        cache[start_index] = 0;
        return false;
    }
    
    bool wordBreak(std::string&& s, std::vector<std::string>& wordDict) {
        size_t size = s.size();
        std::map<char, std::vector<std::string>> eligible_strings;      // List of strings starting with a particular letter
        for(auto& word : wordDict) {
            eligible_strings[word[0]].emplace_back(word);   
        }
        std::vector<int> cache(size,-1);        // Cache -1 => not processed yet 
                                                // 0 => False. Cannot break the string at this index as you will turn out unsuccessful in the end
                                                // 1 => True/successful
        return recursive_word_break(s, size, 0, eligible_strings, cache);
    }

int main(int argc, char **argv)
{
	std::vector<std::string> dict {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    std::cout << wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", dict) << "\n";
	return 0;
}