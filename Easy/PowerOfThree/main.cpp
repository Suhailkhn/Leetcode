#include <stdio.h>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        while(n%3 == 0)
            n /= 3;
        if(n == 1)
            return true;
        return false;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}