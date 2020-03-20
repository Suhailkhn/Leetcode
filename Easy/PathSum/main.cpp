#include <stdio.h>

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        
        return findPathSum(root, sum);
    }
    
    bool findPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        else if(root->left == nullptr && root->right == nullptr) {
            if(root->val == sum)
                return true;
            return false;
        }
        
        return findPathSum(root->left, sum - root->val) || findPathSum(root->right, sum - root->val);
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
