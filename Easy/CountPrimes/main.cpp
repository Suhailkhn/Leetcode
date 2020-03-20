#include <stdio.h>

class Solution {
public:
    int countPrimes(int n) {
        std::vector<bool> isPrime(n + 1, true);
        
        for(long i = 2; i < n; ++i) {
            if(i != 2 && i % 2 == 0)
                continue;
            for(long j = i*i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
        
        int count = 0;
        
        for(int i = 2; i < n; ++i) {
            if(isPrime[i])
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
