#include <stdio.h>

#include <random>
#include <iterator>

static int x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return NULL;
}();

class RandomizedSet {
public:
    std::unordered_set<int> myset;
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = myset.find(val);
        if(it != myset.end()) {
            return false;
        }
        myset.insert(val);
        return true; 
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = myset.find(val);
        if(it != myset.end()) {
            myset.erase(it);
            return true;
        }
        return false;    
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int limit = myset.size();
        std::random_device rand_dev;
        std::mt19937 generator(rand_dev());
        std::uniform_int_distribution<int>  distr(0, limit - 1);
        
        int index = distr(generator);
        auto it = myset.begin();
        std::advance(it, index);
        return *it;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
