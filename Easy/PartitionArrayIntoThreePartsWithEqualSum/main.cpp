#include <vector>
#include <iostream>
#include <unordered_map>

//[3,3,6,5,-2,2,5,1,-9,4]

bool canThreePartsEqualSum(std::vector<int>&& A) {
    int size = A.size();
    
    if(size < 3)
        return false;
    
    std::vector<int> left_sum(size);
    int sum {0}, i {0};
    
    for(auto& n : A) {
        sum += n;
        left_sum[i++] = sum;
    }
    
    std::cout << "LEFT SUM:\n";
    for(auto& n : left_sum) {
        std::cout << n << "\t";
    }
    
    sum = 0;
    std::unordered_map<int, std::vector<int>> right_sum_to_indices;
    
    for(int i = size - 1; i >= 0; --i) {
        sum += A[i];
        right_sum_to_indices[sum].push_back(i);
    }
    
    std::cout << "\n\n\nRIGHT SUM MAPPING:\n";
    for(auto& ele : right_sum_to_indices) {
        std::cout << "\n" << ele.first << "\t->\t{\t";
        for(auto& i : ele.second) {
            std::cout << i << "\t";
        }
        std::cout << "}";
    }
    
    std::cout << "\n";
    
    for(int i = 0; i < size - 2; ++i) {
        if(right_sum_to_indices.find(left_sum[i]) != right_sum_to_indices.end()) {
            for(auto& index : right_sum_to_indices[left_sum[i]]) {
                if(index < i + 2)
                    continue;
                
                if(left_sum[index - 1] - left_sum[i] == left_sum[i])
                    return true;
            }
        }
    }
    
    return false;
}

int main(int argc, char **argv)
{
	canThreePartsEqualSum(std::vector<int>{3,3,6,5,-2,2,5,1,-9,4});
	return 0;
}


class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        
        int s = accumulate(A.begin(), A.end(), 0);        
        if(s%3!=0)
            return false;
        s=s/3;     
        int i=0, sum1=0, c=0;
        
        while(i<A.size()){
            sum1+=A[i];
            if(sum1==s){
                sum1=0;
                c++;
            }
            i++;
        }
        return c==3?true:false;
    }
};