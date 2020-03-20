#include <iostream>
#include <bitset>

    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        uint32_t mask{1}, mask_reversed{2147483648};
        for(int i = 0; i < 32; ++i) {
            if(mask & n) {
                reversed |= mask_reversed; 
            }
            mask <<= 1;
            mask_reversed >>= 1;
        }
        return reversed;
    }

int main(int argc, char **argv)
{
	std::cout << reverseBits(3);
}
