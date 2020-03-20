#include <stdio.h>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size(),target,i = n-1,j,k;
        vector<vector<int>> ans;
        while(i >= 2)
        {
            target = -nums[i];
            j = 0;
            k = i-1;
            while(j < k)
            {
                int temp = nums[j]+nums[k];
                if(temp < target)
                {
                    j++;
                }
                else if(temp > target)
                {
                    k--;
                }
                else
                {
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    ans.push_back(v);
                    j++;
                    k--;
                    while(j < k && nums[j-1] == nums[j])
                    {
                        j++;
                    }
                    while(j < k && nums[k+1] == nums[k])
                    {
                        k--;
                    }
                }
            }
            i--;
            while(nums[i+1]==nums[i])
            {
                i--;
            }
        }
        return ans;
    }
};


int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}


/*

// function to print triplets with 0 sum 
void findTriplets(int arr[], int n) 
{ 
    bool found = false; 
  
    // sort array elements 
    sort(arr, arr+n); 
  
    for (int i=0; i<n-1; i++) 
    { 
        // initialize left and right 
        int l = i + 1; 
        int r = n - 1; 
        int x = arr[i]; 
        while (l < r) 
        { 
            if (x + arr[l] + arr[r] == 0) 
            { 
                // print elements if it's sum is zero 
                printf("%d %d %d\n", x, arr[l], arr[r]); 
                l++; 
                r--; 
                found = true; 
            } 
  
            // If sum of three elements is less 
            // than zero then increment in left 
            else if (x + arr[l] + arr[r] < 0) 
                l++; 
  
            // if sum is greater than zero than 
            // decrement in right side 
            else
                r--; 
        } 
    } 
  
    if (found == false) 
        cout << " No Triplet Found" << endl; 
}