#include <stdio.h>

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min{INT32_MAX}, s_min{INT32_MAX};
        for(int n : nums) {
            if(n <= min) {
                min = n;
            } else if(n <= s_min) {
                s_min = n;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}

Hint: Use Auxiliary Space

Solution:
1) Create an auxiliary array smaller[0..n-1]. smaller[i] should store the index of a number which is smaller than arr[i] and is on left side of arr[i]. smaller[i] should contain -1 if there is no such element.
2) Create another auxiliary array greater[0..n-1]. greater[i] should store the index of a number which is greater than arr[i] and is on right side of arr[i]. greater[i] should contain -1 if there is no such element.
3) Finally traverse both smaller[] and greater[] and find the index i for which both smaller[i] and greater[i] are not -1.



// Alternate.
// A function to fund a sorted subsequence of size 3 
void find3Numbers(int arr[], int n) 
{ 
    // Initializing small and large(second smaller) 
    // by INT_MAX 
    int small = INT_MAX, large = INT_MAX; 
    int i; 
    for (i = 0; i < n; i++) 
    { 
        // Update small for smallest value of array 
        if (arr[i] <= small) 
            small = arr[i]; 
  
        // Update large for second smallest value of 
        // array after occurrence of small 
        else if (arr[i] <= large) 
            large = arr[i]; 
  
        // If we reach here, we found 3 numbers in 
        // increasing order : small, large and arr[i] 
        else
            break; 
    } 
  
    if (i == n) 
    { 
        printf("No such triplet found"); 
        return; 
    } 
  
    // last and second last will be same, but first 
    // element can be updated retrieving first element 
    // by looping upto i 
    for (int j = 0; j <= i; j++) 
    { 
        if (arr[j] < large) 
        { 
            small = arr[j]; 
            break; 
        } 
    } 
  
    printf("%d %d %d", small, large, arr[i]); 
    return; 
} 