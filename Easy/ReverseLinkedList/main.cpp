#include <stdio.h>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;
        ListNode* next_node = head ? head->next : nullptr;
        
        while(current) {
            current->next = previous;
            previous = current;
            current = next_node;
            if(next_node)
                next_node = next_node->next;
        }
        
        head = previous;
        return head;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
