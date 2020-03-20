#include <iostream>
#include <queue>

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // empty tree has height 0
	    if (root == nullptr)
		    return true;

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
                
                if(front) {
                    queue.push(front->left);
                    queue.push(front->right);
                } else {
                    level.emplace_back(NULL);
                    --size;
                    continue;
                }
                
                level.emplace_back(front->val);
                --size;
            }
            
            auto i = level.begin();
            auto j = level.end() - 1;
            
            while(i < j) {
                if(*i && *j) {
                    if(*i == *j) {
                        ++i;
                        --j;
                        continue;
                    }
                    else
                        return false;
                } else if(*i || *j)
                    return false;
                else {
                    ++i;
                    --j;
                    continue;
                }
            }
            
        }
        
        return true;
    }
};


/*
    Recursive
     
      public boolean isSymmetric(TreeNode root) {
        return isMirror(root, root);
    }

public boolean isMirror(TreeNode t1, TreeNode t2) {
    if (t1 == null && t2 == null) return true;
    if (t1 == null || t2 == null) return false;
    return (t1.val == t2.val)
        && isMirror(t1.right, t2.left)
        && isMirror(t1.left, t2.right);
}

 * /



/*
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


    bool isSymmetric(TreeNode* root) {
        // empty tree has height 0
	    if (root == nullptr)
		    return true;

	    // create an empty queue and enqueue root node
	    std::deque<TreeNode*> queue;
	    queue.push_back(root);

	    TreeNode* front = nullptr;

	    // run till queue is not empty
	    while (!queue.empty())
	    {
		    // calculate number of nodes in current level
		    int size = queue.size();

		    // process every node of current level and enqueue their
		    // non-empty left and right child to queue
		    while (size--)
		    {
		    	front = queue.front();
			    queue.pop_front();

			    if (front->left)
				    queue.push_back(front->left);
                else
                    queue.push_back(nullptr);

			    if (front->right)
				    queue.push_back(front->right);
                else
                    queue.push_back(nullptr);
		    }

            size_t j{queue.size() - 1}, i{0};
            
            for(i = 0; i < j; ++i, --j) {
                
                if(queue[i] == nullptr && queue[j] == nullptr) {
//                    queue.pop_front();
//                    queue.pop_back();
                    continue;
                } else if(queue[i] == nullptr || queue[j] == nullptr)
                    return false;
                else {
                    if(queue[i]->val != queue[j]->val)
                        return false;
                    else {
//                        queue.pop_front();
//                        queue.pop_back();
                    }
                } 
            }
            
            for(auto &c : queue) {
                std::cout << c->val << "\t";
            }
            std::cout << "\n";
            
            int k{0};
            for(auto it = queue.begin(); it != queue.end(); it++) {
                if(!(*it))
                    queue.erase(it);
                ++k;
            }
            
            for(auto &c : queue) {
                std::cout << c->val << "\t";
            }
            std::cout << "\n";

	    }

	    return true;
    }


int main(int argc, char **argv)
{
	TreeNode* root = new TreeNode(1);
    TreeNode* r1 = new TreeNode(2);
    TreeNode* r12 = new TreeNode(2);
    
    root->left = r1;
    root->right = r12;
    
    TreeNode* r21 = new TreeNode(3);
    TreeNode* r22 = new TreeNode(3);
    
    r1->left = r21;
    r12->right = r22;
    
    std::cout << std::boolalpha << isSymmetric(root);
//    TreeNode* 23(1);
//    TreeNode* 24(1);
}
