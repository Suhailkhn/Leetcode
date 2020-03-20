#include <iostream>
#include <string>
#include <cctype>
#include <locale>
#include <algorithm>
#include <sstream>

void print(std::string& s) {
    for(auto& c : s)
            std::cout << c;
    std::cout << "\n";
}

bool isPalindrome(std::string s) {
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
        
        std::ostringstream oss;
        for(auto& c : s)
            if(std::isalnum(c))
                oss << c;
        
        s = oss.str();
        
        std::string stream {s};
        
        print(s);
        print(stream);

        std::reverse(stream.begin(), stream.end());
        
        print(stream);
        
        if(s.compare(stream) == 0)
            return true;
        else
            return false;
    }

int main(int argc, char **argv)
{
	isPalindrome("A man, a plan, a canal: Panama");
	return 0;
}
