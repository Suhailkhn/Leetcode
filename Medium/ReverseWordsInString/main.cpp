#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

void print(std::vector<std::string>& s) {
    for(auto& e : s) {
        std::cout << e << "\n";
    }
}

    std::string reverseWords(std::string&& s) {
        std::ostringstream oss;
        int size = s.size();
        int i {0};
        
        std::vector<std::string> vec;           // Store each word in the string
        
        while(i < size) {
            while(std::isspace(s[i])) {         // Remove spaces before words
                if(++i == size)
                    goto OUT;
            }
            
            while(i < size && std::isspace(s[i]) == 0) {    // A non-space character
                oss << s[i++];                              // Store characters of the word
            }
            
            std::cout << "Current word:\t" << oss.str() << '\n';
            vec.push_back(oss.str());
            oss.str("");                                    // Reset for next word
            oss.clear();
        }
        OUT:
        std::cout << "Size is " << vec.size() << "\n";
        print(vec);
        
        std::reverse(vec.begin(), vec.end());
        
        // Construct result
        for(auto& e : vec) {
            oss << e << ' ';
        }
        
        std::string result = oss.str();
        result.pop_back();                          // Remove the trailing space.
        return result;
    }

int main(int argc, char **argv)
{
    std::cout << reverseWords("the sky is blue") << "\n";
	return 0;
}
