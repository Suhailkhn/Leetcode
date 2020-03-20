#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int coinChange(std::vector<int>& coins, int last_coin_index, int amount, std::unordered_map<std::string, int>& lookup) {
    if(amount == 0)
        return 1;
    else if(last_coin_index < 0 || amount < 0)
        return 0;
    
    std::string key = std::to_string(last_coin_index) + "|" + std::to_string(amount);
    if(lookup.find(key) == lookup.end()) {
       int include = coinChange(coins, last_coin_index, amount - coins[last_coin_index], lookup); 
       int exclude = coinChange(coins, last_coin_index - 1, amount, lookup);
        
       lookup[key] = include + exclude;
    }
    return lookup[key];
}

int change(int amount, std::vector<int>&& coins) {
    int size = coins.size();
    std::unordered_map<std::string, int> lookup;
    return coinChange(coins, size - 1, amount, lookup);
}

int main(int argc, char **argv)
{
    int result = change(10, {10});
	std::cout << result << "\n";
	return 0;
}


Faster.
Bottom-up using table.
            amount ->
coins
  |

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        int no_of_coins = coins.size() + 1;                 // Additional 0 coin
        std::vector<std::vector<int>> table(no_of_coins, std::vector<int>(amount + 1, 0));  // ++amount so that table index is 0...amount
        
        // When amount is 0, no. of ways is 1
        for(int i = 0; i < no_of_coins; ++i)
            table[i][0] = 1;
        
        for(int i = 1; i < no_of_coins; ++i) {
            for(int j = 1; j < amount + 1; ++j) {
                if(coins[i-1] > j)                  // Coin is greater than current amount. Can't participate.
                    table[i][j] = table[i-1][j];    // No. of ways excluding the coin.
                else
                    table[i][j] = table[i-1][j] + table[i][j - coins[i-1]];     // Excluding + Including. 
        // When you include a coin of value x, then you have to find no. of ways of curr_amount - x using all coins up till x.
            }
        }
        
        return table.back().back();
    }
};