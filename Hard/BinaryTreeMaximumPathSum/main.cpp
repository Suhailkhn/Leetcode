#include <stdio.h>

class Solution {
public:
    int maximum_sum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        std::unordered_map<TreeNode*, int> cache;
        maxSumIncludingNode(root, cache);
        return maximum_sum;
    }
    
    int maxSumInSubtree(TreeNode* root, std::unordered_map<TreeNode*, int>& cache) {
        if(!root)
            return 0;
        
        if(cache.find(root) != cache.end())
            return cache[root];
        
        int left = maxSumInSubtree(root->left, cache);
        int right = maxSumInSubtree(root->right, cache);
        
        int max = std::max(std::max(left + root->val, right + root->val), root->val);
        
        cache[root] = max;
        
        return max;
    }
    
    void maxSumIncludingNode(TreeNode* root, std::unordered_map<TreeNode*, int>& cache) {
        if(!root)
            return;
        
        int leftSubTree = maxSumInSubtree(root->left, cache);
        int rightSubtree = maxSumInSubtree(root->right, cache);
        
        int max = std::max(std::max(leftSubTree + root->val, rightSubtree + root->val), 
                           std::max(root->val, leftSubTree + root->val + rightSubtree));
        
        if(max > maximum_sum)
            maximum_sum = max;
        
        maxSumIncludingNode(root->left, cache);
        maxSumIncludingNode(root->right, cache);
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
