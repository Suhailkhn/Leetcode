#include <stdio.h>
#include <set>

// Store the nums in a multiset so that they are always sorted
// and maintain an iterator to the median. 
// In case of 2 medians, this iterator will point to the first one.

class MedianFinder {
    std::multiset<int> sorted_nums;
    size_t size;
    std::multiset<int>::iterator it_median;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        it_median = sorted_nums.begin();
        size = 0;
    }
    
    void addNum(int num) {
        sorted_nums.insert(num);
        ++size;
        if(it_median == sorted_nums.end())          // First number
            it_median = sorted_nums.begin();
        else {
            if(num < *it_median && size%2 == 0)
                --it_median;
            else if(num >= *it_median && size%2 != 0)
                ++it_median;
        }
    }
    
    double findMedian() {
        if(size % 2 == 0)
            return (*it_median + *std::next(it_median, 1)) / 2.0;
        else
            return *it_median;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}


// Alternate solutions

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        firstHalf.push(num);
        secondHalf.push(firstHalf.top());
        firstHalf.pop();
        
        if(firstHalf.size() < secondHalf.size())
        {
            firstHalf.push(secondHalf.top());
            secondHalf.pop();
        }
    }
    
    double findMedian() {
        if(firstHalf.size() > secondHalf.size())
            return firstHalf.top();
        else
            return ((double)(firstHalf.top() + secondHalf.top()))/2;
    }
    
private:
    priority_queue<int> firstHalf;
    priority_queue<int, vector<int>, std::greater<int>> secondHalf;
};


// Space efficient
class MedianFinder {
priority_queue<int> maxHeap;
priority_queue<int,vector<int>,greater<int> > minHeap;    
public:
       void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
        if(maxHeap.size()>minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()<minHeap.size())
            return minHeap.top()/1.0;
        return (maxHeap.top() + minHeap.top())/2.0;
    }
};