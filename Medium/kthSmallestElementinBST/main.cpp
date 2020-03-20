#include <stdio.h>

Property: Inorder traversal of a BST yields a sorted sequence.
Do your normal inorder traversal, but instead of storing/printing the node's value, increment a count.
The first time you have to store/print a node's value, it will be the leftmost aka smallest value.

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> s;
        TreeNode* root_copy = root;
        TreeNode* node = nullptr;
        int count{0};
        
        while(true) {
            while(root) {
                s.push(root);
                root = root->left;
            }
            
            if(s.empty())
                break;
            
            root = s.top();
            s.pop();
            
            ++count;
            if(count == k)
                return root->val;
            
            root = root->right;
        }
        
        return root->val;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
