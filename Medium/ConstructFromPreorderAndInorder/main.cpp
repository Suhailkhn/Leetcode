#include <stdio.h>

class Solution {
public:
    std::unordered_map<int, int> value_to_index;
    int preOrderIndex {0};
    
    TreeNode* build(std::vector<int>& preorder, std::vector<int>& inorder,
                    int low, int high) {
        if(low > high)
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preOrderIndex]);
        
        int index = value_to_index[preorder[preOrderIndex]];
        ++preOrderIndex;
        
        root->left = build(preorder, inorder, low, index - 1);
        root->right = build(preorder, inorder, index + 1, high);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i{0};
        for(auto& n : inorder) {
            value_to_index[n] = i++;
        }
        
        int size {i};
        
        if(size == 0)
            return nullptr;
        
        TreeNode* head = build(preorder, inorder, 0, size - 1);
        
        return head;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
