#include <iostream>
#include <vector>
#include <set>

class MinStack {
public:
    /** initialize your data structure here. */
    std::vector<int> stack;
    std::vector<int> min_stack;
    
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
        if(min_stack.empty() || x < min_stack.back())
            min_stack.push_back(x);
        else
            min_stack.push_back(min_stack.back());
    }
    
    void pop() {
        stack.pop_back();
        min_stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min_stack.back();
    }
};

int main(int argc, char **argv)
{
	MinStack m;
    m.push(-2);
    m.push(0);
    m.push(-3);
    
    std::cout << "Min:\t" << m.getMin();  
    m.pop();
    std::cout << "\nTop:\t" << m.top();
    std::cout << "\nMin:\t" <<m.getMin();
	return 0;
}
