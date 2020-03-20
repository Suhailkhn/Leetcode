#include <stdio.h>

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum {0}, carry {1};
        int length = digits.size();
        for(int i = length - 1; i >= 0; --i) {
            sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        
        if(carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
