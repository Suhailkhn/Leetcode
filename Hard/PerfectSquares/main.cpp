#include <stdio.h>

/*
 * Convert the problem to coin change problem.
 */


    int coinChange(int amount, std::vector<int>& coins) {
        int T[amount + 1];          // T[i] stores minimum no. of ways to give change for amount i.
        T[0] = 0;
        int prev_coins;
        int no_of_coins = coins.size();
        
        for(int i = 1; i < amount + 1; ++i) {
            T[i] = INT32_MAX;
            
            for(int c = 0; c < no_of_coins; ++c) {
                if(i - coins[c] >= 0) {         // After considering a coin, the index is still positive.
                    prev_coins = T[i - coins[c]];           // no. of coins needed get amount i - coins[c]
                    if(prev_coins != INT32_MAX)
                        T[i] = min(T[i], prev_coins + 1);    // +1 to add the current coin to the no. of coins needed get amount i - coins[c] 
                }
            }
        }
        return T[amount] == INT32_MAX ? -1 : T[amount];
    }
    
    void build_coins(int n, std::vector<int>& vec) {
        int i{1};
        while(i*i <= n) {
            vec.emplace_back(i*i);
            ++i;
        }
    }
    
    int numSquares(int n) {
        std::vector<int> coins;
        build_coins(n, coins);
        return coinChange(n, coins);
    }

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
