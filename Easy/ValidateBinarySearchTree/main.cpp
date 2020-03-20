#include <iostream>
#include <climits>
using namespace std;

// Data structure to store a Binary Search Tree node
struct Node
{
	int data;
	Node *left, *right;
};

// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->data = key;
	node->left = node->right = nullptr;

	return node;
}

// Recursive function to insert an key into BST
Node* insert(Node* root, int key)
{
	// if the root is null, create a new node an return it
	if (root == nullptr)
		return newNode(key);

	// if given key is less than the root node, recurse for left subtree
	if (key < root->data)
		root->left = insert(root->left, key);

	// if given key is more than the root node, recurse for right subtree
	else
		root->right = insert(root->right, key);

	return root;
}

// Function to determine if given Binary Tree is a BST or not by keeping a
// valid range (starting from [MIN_VALUE, MAX_VALUE]) and keep shrinking
// it down for each node as we go down recursively
bool isBST(Node* node, int minKey, int maxKey)
{
	// base case
	if (node == NULL)
		return true;

	// if node's value fall outside valid range
	if (node->data < minKey || node->data > maxKey)
		return false;

	// recursively check left and right subtrees with updated range
	return isBST(node->left, minKey, node->data) &&
			isBST(node->right, node->data, maxKey);
}

// Function to determine if given Binary Tree is a BST or not
void isBST(Node* root)
{
	if(isBST(root, INT_MIN, INT_MAX))
		printf("This is a BST.");
	else
		printf("This is NOT a BST!");
}

// main function
int main()
{
	Node* root = nullptr;
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };

	for (int key : keys)
		root = insert(root, key);

	// swap nodes
	swap(root->left, root->right);
	isBST(root);

	return 0;
}


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, INT_MIN, INT_MAX, true, true); 
    }
    
    bool isBST(TreeNode* node, int minKey, int maxKey, bool min_flag, bool max_flag) {
        // base case
        if (node == NULL)
		    return true;

	    // if node's value falls inside valid range
	    if (node->val > minKey && node->val < maxKey) {
            if(node->right == nullptr && node->left == nullptr)     // Not required but will save two function calls per leaf node
                return true;
            
             // recursively check left and right subtrees with updated range
	        return isBST(node->left, minKey, node->val, min_flag, max_flag) &&
			        isBST(node->right, node->val, maxKey, min_flag, max_flag);
		    
        }
        
        // Handle cases when val is max or min integer value
        if(minKey == INT_MIN && node->val == INT_MIN && min_flag) {
            if(node->left)          // You won't be able to find a smaller value in the left subtree
                return false;
            
            min_flag = false;       // These cases can only be satisfied once
            return isBST(node->right, node->val, maxKey, min_flag, max_flag);
        }
        else if(maxKey == INT_MAX && node->val == INT_MAX && max_flag) {
            if(node->right)
                return false;
            
            max_flag = false;
            return isBST(node->left, minKey, node->val, min_flag, max_flag);
        }
        
        return false;
    }
};