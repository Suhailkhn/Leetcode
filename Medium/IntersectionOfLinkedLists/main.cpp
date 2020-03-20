#include <stdio.h>

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currentA = headA;
        ListNode* currentB = headB;
        
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        
        // Verify if they intersect
        while(currentA->next) {
            currentA = currentA->next;
        }
        
        while(currentB->next) {
            currentB = currentB->next;
        }
        
        if(currentA != currentB)
            return nullptr;
        else {
            currentA = headA;
            currentB = headB;
        }
        
        // Lists intersect.
        while(currentA != currentB) {
                if(currentA == nullptr) {
                    currentA = headB;
                    continue;
                }
                
                if(currentB == nullptr) {
                    currentB = headA;
                    continue;
                }
                
                currentA = currentA->next;
                currentB = currentB->next;
                
            }
            
        return currentA;
    }
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currentA = headA;
        ListNode* currentB = headB;
        
        std::unordered_set<ListNode*> nodes;
        
        while(currentA) {
            nodes.insert(currentA);
            currentA = currentA->next;
        }
        
        while(currentB) {
            if(nodes.find(currentB) != nodes.end())
                return currentB;
            currentB = currentB->next;
        }
        
        return nullptr;
    }
};


/*
    Approach 3: Two Pointers
Maintain two pointers pApA and pBpB initialized at the head of A and B, respectively. 
Then let them both traverse through the lists, one node at a time.

When pApA reaches the end of a list, then redirect it to the head of B (yes, B, that's right.); 
similarly when pBpB reaches the end of a list, redirect it the head of A.
If at any point pApA meets pBpB, then pApA/pBpB is the intersection node.

To see why the above trick would work, consider the following two lists: 
A = {1,3,5,7,9,11} and B = {2,4,9,11}, which are intersected at node '9'. 

Since B.length (=4) < A.length (=6), pBpB would reach the end of the merged list first, 
because pBpB traverses exactly 2 nodes less than pApA does. 
By redirecting pBpB to head A, and pApA to head B, we now ask pBpB to travel exactly 2 more nodes than pApA would. 
So in the second iteration, they are guaranteed to reach the intersection node at the same time.

If two lists have intersection, then their last nodes must be the same one. 
So when pApA/pBpB reaches the end of a list, record the last element of A/B respectively. 
If the two last elements are not the same one, then the two lists have no intersections.

Complexity Analysis

Time complexity : O(m+n)O(m+n).
Space complexity : O(1)O(1).
 */

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
