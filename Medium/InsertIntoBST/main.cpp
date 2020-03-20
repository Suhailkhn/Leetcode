#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        
        TreeNode* head = root;
        
        while(true) {
           if(val < root->val) {
               if(root->left == nullptr) {
                   root->left = new TreeNode(val);
                   break;
               } else
                   root = root->left;     
           }
            else if(val > root->val) {
                if(root->right == nullptr) {
                    root->right = new TreeNode(val);
                    break;
                } else
                    root = root->right; 
            }
        }
        
        return head;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
