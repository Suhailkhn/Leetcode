#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

    std::vector<Interval> merge(std::vector<Interval>& intervals) {
        int size = intervals.size();
        int i{0};
        std::vector<Interval> result;
        
        if(size == 0)
            return result;
        if(size == 1) {
            result.push_back(intervals[0]);
            return result;
        }
        
        std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        
        for(auto& v : intervals) {
            std::cout << v.start << "\t" << v.end << "\n";
        }
        std::cout << "\n\n\n";
        
        int start_val, end_val;
        
        while(i < size) {
            start_val = intervals[i].start;
            end_val = intervals[i].end;
            
            while(i + 1 < size && end_val >= intervals[i+1].start) 
            {    
                end_val = intervals[i+1].end > end_val ? intervals[i+1].end : end_val;
                ++i;
            }
            
            result.push_back(Interval(start_val, end_val));
            ++i;
        }
        
        return result;
    }

int main(int argc, char **argv)
{
	std::vector<Interval> vec {Interval(1, 4), Interval(0, 4)};
    
    auto vec2 = merge(vec);
    
    for(auto& v : vec2) {
        std::cout << v.start << "\t" << v.end << "\n";
    }
    std::cout << "\n";
}
