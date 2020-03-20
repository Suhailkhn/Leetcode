#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::queue<TreeNode*> queue;
        std::map<int, TreeNode*> height_to_node;
        
        if(!root)
            return {};
        
        int height = 0;
        queue.push(root);
        TreeNode* front = nullptr;
        
        while(!queue.empty()) {
            auto size = queue.size();
            ++height;
            
            while(size) {
                front = queue.front();
                height_to_node[height - 1] = front;
                queue.pop();
                
                if(front->left)
                    queue.push(front->left);
                if(front->right)
                    queue.push(front->right);
                
                --size;
            }
            
        }
        
        std::vector<int> result;
        for(auto& m : height_to_node) {
            result.push_back(m.second->val);
        }
        return result;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
