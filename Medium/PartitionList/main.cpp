#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return nullptr;
        else if(!head->next)
            return head;
        
        ListNode* current_node = nullptr;
        ListNode* lt_end = nullptr;         // End of the 'less than' section
        ListNode* prev_node = nullptr;
        ListNode* goto_next = nullptr;      // Where current node should be positioned after a swap is performed
    
        if(head->val < x) {
            lt_end = head;
        }
        
        prev_node = head;
        current_node = prev_node->next;
        
        while(current_node) {
            if(current_node->val < x) {
                goto_next = current_node->next;
                prev_node->next = current_node->next;
                
                if(lt_end) {            // If an element 'less than' has already been found
                    current_node->next = lt_end->next;
                    lt_end->next = current_node;
                    lt_end = current_node;
                } else {
                    current_node->next = head;
                    head = current_node;
                    lt_end = current_node;
                }
                
                if(prev_node->next != goto_next)     // The swap didn't change anything eg. 1->2->3, swap 2
                     prev_node = prev_node->next;
                
                current_node = goto_next;
                
            } else {
                prev_node = prev_node->next;
                current_node = current_node->next;
            }
        }
        
        return head;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
