#include <stdio.h>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* previous_node = nullptr;
        ListNode* node = head;
        ListNode* next_node = head;
        for(int i = 0; i < n-1; ++i) {
            next_node = next_node->next;
        }
        
        while(next_node->next) {
            previous_node = node;
            node = node->next;
            next_node = next_node->next;
        }
        
        if(previous_node) {
            previous_node->next = node->next;
            delete node;
        } else if(node == next_node){
            head = nullptr;
            delete node;
        } else {
            head = node->next;
            delete node;
        }
        
        return head;
    }

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
