#include <queue>

class MyStack {
public:
    std::queue<int> myqueue;
    std::queue<int> temp;
    int top_of_stack {NULL};
    
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        myqueue.push(x);
        top_of_stack = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int num{NULL}, next_top, popped_element, size{0};
        
        while(!myqueue.empty()) {
            next_top = num;
            num = myqueue.front();
            myqueue.pop();
            temp.push(num);
            ++size;
        }
        
        popped_element = num;
        
        while(size > 1) {
            num = temp.front();
            temp.pop();
            myqueue.push(num);
            --size;
        }
        
        temp.pop();
        
        if(myqueue.empty())
            top_of_stack = NULL;
        else
            top_of_stack = next_top;
        
        return popped_element;
    }
    
    /** Get the top element. */
    int top() {
        return top_of_stack;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return myqueue.empty();
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
