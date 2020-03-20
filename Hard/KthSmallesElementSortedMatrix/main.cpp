#include <iostream>
#include <vector>
#include <algorithm>

// Using Heap
int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<int> heap;
    for (auto line : matrix) {
        for (auto elem : line) {
            heap.push(elem);
            if (heap.size() > k) {
                heap.pop();
            }
        }
    }
    return heap.top();
}

// Using binary search
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int mid = left + (right - left) /2;
            int count = search_less_equal(matrix, mid);
            if (count < k) left = mid+1;
            else right = mid;
        }
        return left;
    }
    
    int search_less_equal(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), i = n-1, j = 0, res = 0;
        while (i>=0 && j < n) {
            if (matrix[i][j] <= target) {
                res += i+1;
                ++j;
            } else --i;
        }
        return res;
    }
};





















// WRONG
    int diagonal_no(int k, int n, bool upper_triangle) {
        int elements_passed = upper_triangle ? 0 : n*(n+1)/2;
        int add_on = upper_triangle ? 1 : n-1;
        int number = 0;
        while(k > elements_passed) {
            ++number;
            elements_passed += add_on;
            upper_triangle ? ++add_on : --add_on;
        }
        return number;
    }
    
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(k == 1)
            return matrix[0][0];
        else if(k == n*n)
            return matrix[n-1][n-1];
        
        bool upper_triangle {false};
        if(k <= n*(n+1)/2)
            upper_triangle = true;
        
        std::vector<int> diagonal;
        int mthsmallest_in_diagonal;
        
        if(upper_triangle) {
            int d = diagonal_no(k, n, upper_triangle);
            
            // Indices of diagonal
            int i {d-1};    
            int j {0};
            
            // Position in the sorted diagonal
            mthsmallest_in_diagonal = k - i*(i+1)/2;
            
            while(i >= 0) {
                diagonal.push_back(matrix[i][j]);
                --i;
                ++j;
            }
            
            std::sort(diagonal.begin(), diagonal.end());
            
            return diagonal[mthsmallest_in_diagonal - 1];
            
        } else {
            int d = diagonal_no(k, n, upper_triangle);
            
            // Indices of diagonal
            int i {d};    
            int j {n-1};
            
            // Position in the sorted diagonal
            k -= n*(n+1)/2;
            mthsmallest_in_diagonal = k - ((n-1)*(n)/2 - (n-d)*(n-d+1)/2);
            
            while(i < n) {
                diagonal.push_back(matrix[i][j]);
                ++i;
                --j;
            }
            
            std::sort(diagonal.begin(), diagonal.end());
            
        }
        
        return diagonal[mthsmallest_in_diagonal - 1];
    }

int main(int argc, char **argv)
{
	std::cout << diagonal_no(25, 5, false);
	return 0;
}
