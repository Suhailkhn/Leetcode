#include <stdio.h>

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        int n = nums.size();
        convert(nums, 0, n-1, root);
        return root;
    }
    
    void convert(vector<int>& nums, int low, int high, TreeNode* &root) {
        if(low > high)
            return;
        
        int mid = (low+high)/2;
        
        root = new TreeNode(nums[mid]);
        convert(nums, low, mid-1, root->left);
        convert(nums, mid+1, high, root->right);
    }
};