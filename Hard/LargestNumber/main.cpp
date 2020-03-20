#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

/*
    static bool custom_sort(int& a, int& b) {
        std::vector<int> a_digits, b_digits;
        int digit, temp = a;
        while(temp > 0) {
            digit = temp%10;
            a_digits.push_back(digit);
            temp = temp/10;
        }
        temp = b;
        while(b > 0) {
            digit = temp%10;
            b_digits.push_back(digit);
            temp = temp/10;
        }
        
        if(a_digits.size() == b_digits.size())
            return a > b;
        else {
            int i = a_digits.size() - 1;
            int j = b_digits.size() - 1;
            
            while(i >= 0 && j >= 0) {
                if(a_digits[i] != b_digits[j]) {
                    if(a_digits[i] > b_digits[j])
                        return true;
                    else
                        return false;
                }
                --i;
                --j;
            }
            
            if(i >= 0) {
                if(a_digits[i] > b_digits.back())
                    return true;
                else 
                    return false;
            }
            
            if(j >= 0) {
                if(b_digits[j] > a_digits.back())
                    return true;
                else 
                    return false;
            }
        }
        return false;   
    }
    
    std::string largestNumber(std::vector<int>&& nums) {
        std::sort(nums.begin(), nums.end(), custom_sort);
        std::ostringstream oss;
        for(auto& n : nums) {
            oss << n;
        }
        return oss.str();
    }

*/    
    bool custom_sort(std::string& a, std::string& b) {
        return a+b > b+a;  
    }
    
    std::string largestNumber(std::vector<int>&& nums) {
        std::vector<std::string> vec(nums.size());
        int i = 0;
        for(auto& n : nums) {
            vec[i++] = std::to_string(n);
        }
        
        std::sort(vec.begin(), vec.end(), custom_sort);
        if(vec[0][0] == '0' || (vec[0].compare("0") == 0))
            return "0";
        
        std::ostringstream oss;
        for(auto& n : vec) {
            oss << n;
        }
        
        //std::string result = oss.str();
        // if(result[0] == '0')
        //     return "0";
        
        return oss.str();
    }

int main(int argc, char **argv)
{
	std::cout << largestNumber({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}) << '\n';
	return 0;
}
