#include <stdio.h>

// Important Resource
// https://www.hackerearth.com/practice/notes/bit-manipulation/

// n & (n-1) reduces the state of the number from having x bits to x-1 bits
// Relies on number of 1s in the number
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n > 0) {
            n = n & (n-1);
            ++count;
        }
        return count;
    }
};


// Alternate and less efficient approach
// Loop through and test each bit for 1
/*
public int hammingWeight(int n) {
    int bits = 0;
    int mask = 1;
    for (int i = 0; i < 32; i++) {
        if ((n & mask) != 0) {
            bits++;
        }
        mask <<= 1;
    }
    return bits;
}
 */

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
