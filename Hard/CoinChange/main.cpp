#include <stdio.h>

/*
    We have a bottom-up solution here.
    Suppose we have coins {2,3,5} and we want to get amount 10.
    Then the final result is the minimum of the result for 8, 7 and 5.
    Since this is bottom-up they have already been calculated.
    No. of ways to get 5 is 1, so for 10 is 1 + 1.
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
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
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
