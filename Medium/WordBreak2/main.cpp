#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Solution {
public:
    // Each function has the sentence that is formed till the previous index.
    // Each successful word at the current index will be then appended to it and 
    // upon successfully reaching the end of the string, the sentence thus formed will be pushed into result
    void recursive_word_break(std::string& s, int length, size_t start_index, std::string sentence_until_index,
                              std::map<char, std::vector<std::string>>& eligible_strings, std::vector<int>& cache,
                              std::vector<std::string>& sentences) {
        
        bool found_a_match {false};
        if(eligible_strings.find(s[start_index]) != eligible_strings.end()) {   // There are words starting with the char at index
            for(auto& word : eligible_strings[s[start_index]]) {            // For all the eligible words at the current index
                if(start_index + word.size() - 1 >= length)                 // Word is longer than the remaining part of string
                    continue;
                if(s.compare(start_index, word.size(), word) == 0) {    // Word matches corresponding part of string
                    if(start_index + word.size() - 1 == length-1) {     // Word completes the String
                        cache[start_index] = 1;
                        found_a_match = true;
                        sentence_until_index == "" ? sentences.emplace_back(word) : sentences.emplace_back(sentence_until_index + " " + word);
                    }
                    else {
                        if(cache[start_index + word.size()] != 0) {     // We don't end up on an index from where it is impossible to succeed
                            found_a_match = true;
                            recursive_word_break(s, length, start_index + word.size(), sentence_until_index == "" ? word : sentence_until_index + " " + word, eligible_strings, cache, sentences); 
                        }
                    }
                }
            }
        }
        
        if(!found_a_match)                  // Did not find any word completely matching at this index.
            cache[start_index] = 0;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        size_t size = s.size();
        
        std::map<char, std::vector<std::string>> eligible_strings;    // List of words starting with a particular character
        for(auto& word : wordDict) {
            eligible_strings[word[0]].emplace_back(word);   
        }
        
        std::vector<int> cache(size,-1);        // Cache -1 => not processed yet 
                                                // 0 => False. Cannot break the string at this index as you will turn out unsuccessful in the end
                                                // 1 => True/successful
        
        std::vector<std::string> sentences;
        recursive_word_break(s, size, 0, "",eligible_strings, cache, sentences);
        return sentences;
    }
};

int main(int argc, char **argv)
{
	
	return 0;
}

/*
sentences.emplace_back(sentence_until_index + " " + word);
sentences.back().erase(sentences.back().begin(), std::find_if(sentences.back().begin(), sentences.back().end(), [](int ch) {
        return !std::isspace(ch);
}));