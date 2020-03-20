// Peak valley approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int total_profit{0}, current_high, flag{0};
        
        if(size == 0 || size == 1)
            return 0;
    
        for(int i = 0, j = 1; j < size; ++j) {
            current_high = prices[i];
            while(current_high <= prices[j]) {
                flag = 1;
                current_high = prices[j];
                ++j;
            }
            if(flag) {
                total_profit += prices[j-1] - prices[i];
            }
            i = j;
            flag = 0;
        }
        
        return total_profit;
    }
};



// For only one transaction
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        
        if(size == 0 || size == 1)
            return 0;
    
        int max_profit{0}, current_min{INT_MAX};
        
        for(int i = 0; i < size; ++i) {
            if(prices[i] < current_min)
                current_min = prices[i];
            else if(prices[i] - current_min > max_profit)
                max_profit = prices[i] - current_min;
        }
        
        return max_profit;
    }
};





#include <iostream>
#include <map>
#include <functional>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices);
int sell(auto p, std::vector<int>& prices, int sold);

std::vector<int> sold_days{-1};                 // Holds the days when a stock was sold, used to prevent Multiple Transactions

int main(int argc, char **argv)
{
	std::vector<int> prices = {7,1,5,3,6,4};
    std::cout << maxProfit(prices) << std::endl;
}

//2,1,2,1,0,0,1

int maxProfit(std::vector<int>& prices) {
        std::multimap<int,int, std::greater<int>> stock_price;
        int i {0}, buy_index {-1}, j;
        int profit {0};
        int previous_sold;                      // Can only buy from the (previous_sold day + 1) till today. Prevents MTs.
        
        std::vector<int> available_days;
        for(unsigned int i = 0; i < prices.size(); i++)
            available_days.emplace_back(i);
        
        std::vector<int> not_available_days {};
        
        for(auto &price: prices) {
            stock_price.insert({price, i});
            i++;
        }
        
        for(const auto &p: stock_price) {
            
            // Day is available to sell, find the previous day when I sold a stock
            if(std::find(not_available_days.begin(), not_available_days.end() ,p.second) == not_available_days.end()) {     // Day is available to sell
                
                for(auto &s : sold_days) {
                    if(s <= p.second)
                        previous_sold = s;
                }
               
                buy_index = sell(p, prices, previous_sold);
                if(buy_index != -1) {           // Day is available to sell
                
                    // buy_index is a valid/available day to buy
                    if(std::find(not_available_days.begin(), not_available_days.end() ,buy_index) == not_available_days.end()) {
                        j = 0;
                
                        for(auto i = available_days.begin(); i != available_days.end(); i++) {
                            if(j == buy_index) {
                                auto start = i;
                                auto end = start + sold_days.back() - buy_index + 1;
                                
                                // Make the period when a transaction occured not available
                                for(auto i = start; i != end; i++) 
                                    not_available_days.emplace_back(*i);
                                
                                break;
                            }
                            j++;
                        }
                    } else
                        continue;
                
                    profit += (p.first - prices.at(buy_index));
                }
                std::sort(sold_days.begin(), sold_days.end());
                
            }
            
        }
        
        return profit;
}


// Can I sell at that particular day? If so, tell me when can I buy.
int sell(auto p,  std::vector<int>& prices, int sold) {
        int sell_index = p.second;
        int buy_index = -1;
        int i;
        int flag {0};
        int previous_lowest {p.first};
        if(sell_index == 0) {                           // Can't sell on the first day
            return -1;
        } else {
            for(i = sell_index - 1; i > sold; --i) {    // Look for the lowest stock price from the day before
                if(prices[i] > previous_lowest) {       // the selling day till the day when a stock was last sold
                    if(flag == 1)
                        break;
                }
                else {
                    buy_index = i;
                    previous_lowest = prices[i];
                    flag = 1;
                }
            }
                
            if(i == sold && buy_index == -1)
                return -1;
            else {
                if(buy_index > -1)
                    sold_days.emplace_back(sell_index);
                return buy_index;
            }
                
        }
}