#include <stdio.h>
#include <cmath>
#include <iostream>

int digits(int y) {
    if(y == 0)
        return 1;
    
    int no_of_digits {0};
    while(y > 0) {
        ++no_of_digits;
        y /= 10;
    }
    
    return no_of_digits;
}

int reverse(int x) {
    if(x == INT_MIN)
        return 0;
    int ognum = x >= 0 ? x : -x;
    int digit, number {0}, number_to_add {0};
    int no_of_digits = digits(ognum) - 1;
    
    while(ognum > 0) {
        digit = ognum % 10;
        number_to_add = digit * pow(10,no_of_digits);
        if(number_to_add >= 0 && INT_MAX - number >= number_to_add)
            number += number_to_add;
        else
            return 0;
        ognum = ognum / 10;
        --no_of_digits;
    }
    
    if(x >= 0)
        return number;
    else
        return -number;
}

int main(int argc, char **argv)
{
	reverse(1534236469);
	return 0;
}
