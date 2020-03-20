#include <stdio.h>

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int>> paths;
        if(!root)
            return paths;
        
        std::vector<int> current_path;
        findPathSum(root, sum, current_path, paths);
        
        return paths;
    }
    
    void findPathSum(TreeNode* root, int sum, std::vector<int> current_path, std::vector<std::vector<int>>& paths) {
        if(!root)
            return;
        else if(root->left == nullptr && root->right == nullptr) {
            if(root->val == sum) {
                current_path.push_back(root->val);
                paths.emplace_back(current_path);
            }
            return;
        }
        
        current_path.push_back(root->val);
        findPathSum(root->left, sum - root->val, current_path, paths);
        findPathSum(root->right, sum - root->val, current_path, paths);
    }
};


// More efficient solution by avoiding creating copies of current_path. Backtracking.
// Each child undoes whatever operation it has performed on current_path before returning 
// so by the time you reach to the parent from the left subtree, current_path is as it was before going down the left subtree.
// Which means you can directly pass it to the right subtree.
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        std::vector<std::vector<int>> paths;
        if(!root)
            return paths;
        
        std::vector<int> current_path;
        findPathSum(root, sum, current_path, paths);
        
        return paths;
    }
    
    void findPathSum(TreeNode* root, int sum, std::vector<int>& current_path, std::vector<std::vector<int>>& paths) {
        if(!root)
            return;
        else if(root->left == nullptr && root->right == nullptr) {
            if(root->val == sum) {
                current_path.push_back(root->val);
                paths.push_back(current_path);
                current_path.pop_back();
            }
            return;
        }
        
        current_path.push_back(root->val);
        
        findPathSum(root->left, sum - root->val, current_path, paths);
        findPathSum(root->right, sum - root->val, current_path, paths);
        
        current_path.pop_back();
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
