#include <stdio.h>

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::queue<TreeNode*> queue;
        std::vector<std::vector<int>> levels;
        
        if(!root)
            return {};
        
        queue.push(root);
        TreeNode* front = nullptr;
        
        while(!queue.empty()) {
            auto size = queue.size();
            levels.push_back({});
            
            while(size) {
                front = queue.front();
                queue.pop();
                
                if(front->left)
                    queue.push(front->left);
                if(front->right)
                    queue.push(front->right);
                
                levels.back().emplace_back(front->val);
                --size;
            }
        }
        
		// Normal Level Order Traversal code until here
		
		// Reverse alternate levels
		
        bool reverse {false};
        for(auto& level : levels) {
            if(reverse) {
                std::reverse(level.begin(), level.end());
            }
            
            reverse = !reverse;
        }
        
        return levels;
        
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
