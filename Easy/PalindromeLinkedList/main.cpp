#include <stdio.h>
#include <vector>

//  Complexity : O(n) time and O(n) space

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<int> nums;
        
        while(head) {
            nums.emplace_back(head->val);
            head = head->next;
        }
        
        int i{0}, j{nums.size() - 1};
        
        while(i < j) {
            if(nums[i] != nums[j])
                return false;
            ++i;
            --j;
        }
        
        return true;
    }
};

/*
    Algorithm for O(1) space:
     * Find middle of linked list - O(n)
     * Reverse right half          - O(n)
     * Compare two halves one by one using pointer to head and middle - O(n)
*/


int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
