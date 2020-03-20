#include <iostream>
#include <vector>
#include <string>

template<typename T>
void print(std::vector<T> vec) {
    for(const T& ele : vec)
        std::cout << ele << "\t";
    std::cout << "\n";
}


/*
 * We use a stack where we push index of all the opening braces we come across
 * and pop the stack on encountering a closing brace.
 * We use a boolean array of string size which tells us whether a bracket has a pair.
 * When we pop from the stack, we have found a pair and hence set the flag for both.
 * Lastly calculate the longest consecutive sequence of true in the boolean array which is the result.
 */


int longestValidParentheses(std::string s) {
    int i{0};
    std::vector<int> opening_braces_index;      // Stack where opening braces are pushed.
    std::vector<bool> found_pair(s.size(), false);
        
    for(auto& c : s) {
        if(c == '(')
            opening_braces_index.emplace_back(i);
        else if(!opening_braces_index.empty()){
            found_pair[i] = true;
            found_pair[opening_braces_index.back()] = true;
            opening_braces_index.pop_back();
        }
        ++i;   
    }
        
    int max_count{0}, count{0};
    for(auto b : found_pair) {
        if(b)
            ++count;
        else {
            if(count > max_count)
                max_count = count;
            count = 0;
        }
    }
    if(count > max_count)
        max_count = count;
        
    std::cout << "Opening Braces Stack:\n";
    print(opening_braces_index);
        
    std::cout << "Found Pair:\n";
    print(found_pair);
        
    return max_count;
}

int main(int argc, char **argv)
{
	std::cout << longestValidParentheses("(()") << "\n";
	return 0;
}
