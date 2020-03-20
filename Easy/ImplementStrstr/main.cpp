#include <stdio.h>

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        size_t found = haystack.find(needle);
        if(found != std::string::npos)
            return found;
        else
            return -1;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
