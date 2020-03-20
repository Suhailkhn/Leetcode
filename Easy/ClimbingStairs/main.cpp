#include <stdio.h>

// DP
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        std::vector<int> vec(n);
        vec[0] = 1;
        vec[1] = 2;
        for(int i = 2; i < n; ++i) {
            vec[i] = vec[i-1] + vec[i-2];
        }
        return vec.back();
    }
};

// Alternate using Fibonacci, constant space solution
public class Solution {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
}

// if use formula for nth fib, its a logn solution since pow takes logn time


int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
