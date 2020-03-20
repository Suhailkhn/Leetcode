#include <stdio.h>

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> s;
        TreeNode* root_copy = root;
        TreeNode* node = nullptr;
        
        if(!root)
            return result;
        
        while(true) {
            while(root) {
                s.push(root);
                root = root->left;
            }
            
            if(s.empty())
                break;
            
            root = s.top();
            s.pop();
            result.push_back(root->val);
            
            root = root->right;
        }
        
        return result;
    }
};


int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
