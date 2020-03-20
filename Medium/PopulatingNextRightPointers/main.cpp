#include <stdio.h>

class Solution {
public:
    Node* connect(Node* root) {
        std::queue<Node*> queue;
        std::vector<Node*> level;
        
        if(!root)
            return {};
        
        queue.push(root);
        Node* front = nullptr;
        
        while(!queue.empty()) {
            auto size = queue.size();
            level.clear();
            
            while(size) {
                front = queue.front();
                queue.pop();
                
                if(front->left)
                    queue.push(front->left);
                if(front->right)
                    queue.push(front->right);
                
                level.emplace_back(front);
                --size;
            }
            
            // Normal Level Order Traversal code until here
            
            // Attach the next pointers of each node in a level
            for(auto it = level.begin(); it != level.end() - 1; ++it) {
                (*it)->next = *(it+1);
            }
        }
        
        return root;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
