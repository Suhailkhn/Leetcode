#include <stdio.h>

class Solution {
public:
    TreeNode* LCA(TreeNode* root, TreeNode* smaller, TreeNode* larger) {
        if(root->val == smaller->val || root->val == larger->val)
            return root;
        else if(smaller->val < root->val && root->val < larger->val)    // They diverge at this node
            return root;
        
        // They are on the same side
        if(smaller->val < root->val)
            return LCA(root->left, smaller, larger);
        
         return LCA(root->right, smaller, larger);   
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* smaller = nullptr;
        TreeNode* larger = nullptr;
        
        if(!root)
            return nullptr;
        
        if(p->val < q->val) {
            smaller = p;
            larger = q;
        } else {
            smaller = q;
            larger = p;
        }
        
        return LCA(root, smaller, larger);
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
