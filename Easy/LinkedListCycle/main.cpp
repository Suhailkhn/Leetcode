#include <stdio.h>

// O(n) Time O(n) Space

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        
        int i{0};
        std::unordered_set<ListNode*> node_set;
        
        while(head) {
            if(node_set.find(head) != node_set.end())
                return true;
            else
                node_set.insert(head);
            head = head->next;
        }
        
        return false;
    }
};

/*
    The space complexity can be reduced to O(1) by considering two pointers at different speed 
     - a slow pointer and a fast pointer. 
    The slow pointer moves one step at a time while the fast pointer moves two steps at a time
      
    Alternate:
     Set each node's value to NULL as you go through and check every node's value.
     If you come across NULL then there is a loop.
 */

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
