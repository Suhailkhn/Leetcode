#include <stdio.h>

class Solution {
public:
    int titleToNumber(string s) {
        int high = s.size() - 1;
        int column_no{0};
        
        for(int i = high, j = 0; i >= 0; --i, ++j) {
            column_no += (s[i] - 'A' + 1) * std::pow(26, j);
        }
        
        return column_no;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
