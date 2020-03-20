#include <vector>
#include <queue>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> queue;
        std::vector<std::vector<int>> levels;
        
        if(!root)
            return {};
        
        queue.push(root);
        TreeNode* front = nullptr;
        
        while(!queue.empty()) {
            auto size = queue.size();
            std::vector<int> level;
            
            while(size) {
                front = queue.front();
                queue.pop();
                
                if(front->left)
                    queue.push(front->left);
                if(front->right)
                    queue.push(front->right);
                
                level.emplace_back(front->val);
                --size;
            }
            
            levels.emplace_back(level);
        }
        
        return levels;
    }
};

/*
 * Recursive solution
 
    vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> result;
	dolevelordertraversal(result, root, 0);
	return result;
}

void dolevelordertraversal(vector<vector<int>> &result, TreeNode *root, int level) {
	if(root == NULL) return;
	if(result.size() == level) result.push_back(vector<int>());
	result[level].push_back(root->val);
	dolevelordertraversal(result, root->left, level+1);
	dolevelordertraversal(result, root->right, level+1);
}
*/