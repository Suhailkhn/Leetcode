#include <stdio.h>

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        else if(root->left == nullptr && root->right == nullptr)
            return 1;
        else {
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);
            if(left > right)
                return left + 1;
            else
                return right + 1;
        }
        
    }
};

/*
    // Data structure to store a Binary Tree node
struct Node
{
	int key;
	Node *left, *right;
};

// Iterative function to calculate height of given binary tree
// by doing level order traversal of the tree
int height(Node *root)
{
	// empty tree has height 0
	if (root == nullptr)
		return 0;

	// create an empty queue and enqueue root node
	list<Node*> queue;
	queue.push_back(root);

	Node* front = nullptr;
	int height = 0;

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

			if (front->right)
				queue.push_back(front->right);
		}

		// increment height by 1 for each level
		height++;
	}

	return height;
}
 */


int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
