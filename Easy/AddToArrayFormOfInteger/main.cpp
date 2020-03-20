#include <stdio.h>

class Solution {
public:
    std::vector<int> GenerateDigitArray(int k) {
        if(k == 0) {
            return {0};
        }
        
        std::vector<int> digits;
        
        while(k > 0) {
            int digit = k % 10;
            digits.emplace_back(digit);
            k /= 10;
        }
        
        std::reverse(digits.begin(), digits.end());
        
        return digits;
    }
    
    vector<int> addToArrayForm(vector<int>& A, int k) {
        std::vector<int> k_array = GenerateDigitArray(k);
        int k_length = k_array.size();
        int length = A.size();
        
        int k_index {k_length - 1}, index {length - 1};
        int sum {0}, carry {0};
        std::vector<int> result;
        
        while(index >= 0 && k_index >= 0) {
            sum = A[index] + k_array[k_index] + carry;
            result.push_back(sum % 10);
            carry = sum / 10;
            
            --index;
            --k_index;
        }
        
        while(index >= 0) {
            sum = A[index] + carry;
            result.push_back(sum % 10);
            carry = sum / 10;
            --index;
        }
        
        while(k_index >= 0) {
            sum = k_array[k_index] + carry;
            result.push_back(sum % 10);
            carry = sum / 10;
            --k_index;
        }
        
        if(carry == 1) {
            result.push_back(1);
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
