#include <stdio.h>

static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();

class Solution {
public:
    bool isValid(string s) {
        std::vector<char> stack;
        
        for(auto& c : s) {
            if(c == '(' || c == '{' || c == '[')
                stack.push_back(c);
            else {
                if(stack.size() == 0)
                    return false;
                
                char s = stack.back();
                
                switch(c) {
                    case ')':
                        if(s != '(')
                            return false;
                        break;
                    case '}':
                        if(s != '{')
                            return false;
                        break;
                    case ']':
                        if(s != '[')
                            return false;
                        break;
                }
                
                stack.pop_back();
            }
        }
        
        if(stack.size() > 0)
            return false;
        
        return true;
    }
};


int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
