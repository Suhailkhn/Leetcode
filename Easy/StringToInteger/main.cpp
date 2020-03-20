#include <iostream>
#include <string>

int myAtoi(std::string str) {
    try{
        return std::stoi(str);
    } catch (std::invalid_argument){
        return 0;
    } catch (std::out_of_range) {
        int i {0};
        while(str[i] == ' ')
            ++i;
        if(str[i] == '-')
            return INT32_MIN;
        else
            return INT32_MAX;
    }
}

int main(int argc, char **argv)
{
	std::cout << myAtoi("     -91283472332");
	return 0;
}
