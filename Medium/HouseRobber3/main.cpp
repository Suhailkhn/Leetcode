#include <stdio.h>

class Solution {
public:
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        
        auto result = robHouse(root);
        int robRoot = result.first;
        int leaveRoot = result.second;
        
        return robRoot > leaveRoot ? robRoot : leaveRoot;
    }
    
	// For each house this will return {first, second} where 
	// first is the total amount of money that can be robbed in the subtree of the current house, 
	// if we rob the current house
	// second is the total amount of money that can be robbed in the subtree of the current house,
	// if we don't rob the current house
    std::pair<int, int> robHouse(TreeNode* root) {
        if(!root)
            return {0, 0};
        else if(root->left == nullptr && root->right == nullptr)
            return {root->val, 0};
        
        auto leftHouses = robHouse(root->left);
        auto rightHouses = robHouse(root->right);
        
		// If we rob the current house, we cannot rob the left & right houses directly connected
        int robCurrentHouse = root->val + leftHouses.second + rightHouses.second;
        
        int robBothNextHouses = leftHouses.first + rightHouses.first;
        int leaveBothNextHouses = leftHouses.second + rightHouses.second;
        int robOnlyNextLeft = leftHouses.first + rightHouses.second;
        int robOnlyNextRight = leftHouses.second + rightHouses.first;
        
        int leaveCurrentHouse = std::max(std::max(robBothNextHouses, leaveBothNextHouses), 
                                         std::max(robOnlyNextLeft, robOnlyNextRight));
        
        return {robCurrentHouse, leaveCurrentHouse};
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
