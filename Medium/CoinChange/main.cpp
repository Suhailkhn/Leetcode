#include <iostream>
#include <vector>
#include <algorithm>

// Does not work

int coinChange(std::vector<int>&& coins, int amount) {
        std::sort(coins.begin(), coins.end());
        int size = coins.size();
        int no_of_coins{0};
        int current_coin, i{size-1};
        int amount_remaining {amount};
        
        while(amount_remaining != 0 && i >= 0) {
            current_coin = coins[i];
            no_of_coins += amount_remaining/current_coin;
            amount_remaining -= current_coin*(amount_remaining/current_coin);
            --i;
        }
        
        if(amount_remaining > 0)
            return -1;
        
        return no_of_coins;
    }

int main(int argc, char **argv)
{
	std::cout << coinChange({186,419,83,408}, 6249) << "\n";
	return 0;
}
