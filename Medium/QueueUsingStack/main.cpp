#include <stack>

class MyQueue {
public:
    std::stack<int> myqueue;
    std::stack<int> temp;
    int front{NULL};
    
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        myqueue.push(x);
        if(!front)
            front = x;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int num, front_element;
        
        while(!myqueue.empty()) {
            num = myqueue.top();
            myqueue.pop();
            temp.push(num);
        }
        
        front_element = temp.top();
        temp.pop();
        
        if(!temp.empty())
            front = temp.top();
        else
            front = NULL;
        
        while(!temp.empty()) {
            num = temp.top();
            temp.pop();
            myqueue.push(num);
        }
        
        return front_element;
    }
    
    /** Get the front element. */
    int peek() {
       return front; 
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return myqueue.empty();
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
