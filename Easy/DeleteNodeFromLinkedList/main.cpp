#include <stdio.h>

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* new_node = node->next;
        node->next = node->next->next;
        delete new_node;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
