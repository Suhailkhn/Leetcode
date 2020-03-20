#include <stdio.h>

/*
    Data structure brainstorm:
    We want a data structure that gives us the max in constant time 
    and has constant time insertion, removal.
    Heap - has logn insertion. Can't search and remove elements.
    
    Priority Queue - is a heap only. Max element always at front but extra effort
    needed to detect out of bounds. Can store (value, index) pair, but before
    using the max, check its index and remove it if it is out of bounds.
    Problem is, since it is a heap, every time we insert an element, it takes logn
    time and however many times we delete the max, each time it would again take
    logn time to build heap again. Also it would take O(n) space.
    
    Queue - We want the greatest element to land in front that means when we
    insert an element we keep popping the back while that element is greater.
    If we were storing values and the elements value is least then it will remain last
    even if elements in front of it are out of bounds.
    Hence we need some way to remove those elements from the front as well.
    Enter Dequeue....
    We can get the same behaviour by storing indices instead of values since the input
    container is a vector and provides random access and hence we can get the values instantly.
    Now we can pop elements from the front while the index stored is less than the lower
    index of the current sliding window.
    
    We try to maintain the deque in such a way that
    at whatever index i we might be in the array, the front
    of the deque will always have the index of the largest element
    lying in the window that ends at i
    
    If we stored values instead of indices then we would need another map 
    or something to find out if the max at the front is out of the window.
    Hence storing indices makes it easier and efficient to remove 
    out of range elements from the front.
    
    So at each iteration we first remove all elements at the front
    which are out of bounds.
    Then we keep popping the back while the element to be inserted 
    is greater than the back, and then insert its index.
    
    Each element will be inserted in the queue only once and removed
    only once. Hence we access 2n elements and it is still O(n) time.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> result;
        int size = nums.size();
        
        if(k == 0 || size == 0)
            return result;
        
        std::deque<int> deq;
        
        // First window
        for(int i = 0; i < k; ++i) {
            while(!deq.empty() && nums[i] >= nums[deq.back()])
                deq.pop_back();
            deq.push_back(i);
        }
        
        for(int i = k; i < size; ++i) {
            result.push_back(nums[deq.front()]);        // Previous window result
            
            // Adjust dequeue for current window
            while(!deq.empty() && deq.front() <= i-k)   // Out of bounds elements from front
                deq.pop_front();
            
            while(!deq.empty() && nums[i] >= nums[deq.back()])  // current element is greeater
                deq.pop_back();
            
            deq.push_back(i);
        }

        result.push_back(nums[deq.front()]);        // Final window result
        
        return result;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
