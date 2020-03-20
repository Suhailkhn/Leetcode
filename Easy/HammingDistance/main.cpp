#include <stdio.h>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        return hammingWeight(n);
    }
    
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n > 0) {
            n = n & (n-1);
            ++count;
        }
        return count;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
