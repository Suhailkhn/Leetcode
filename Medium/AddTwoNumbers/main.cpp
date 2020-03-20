#include <stdio.h>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* list1 = l1;
        ListNode* list2 = l2;
        ListNode* head = new ListNode(0);
        ListNode* current = head;
        ListNode* newnode = nullptr;
        
        int sum{0}, carry{0};
        
        while(list1 && list2) {
            sum = list1->val + list2->val + carry;
            carry = sum/10;
            newnode = new ListNode(sum % 10);
            
            current->next = newnode;
            current = current->next;
            list1 = list1->next;
            list2 = list2->next;
        }
        
        while(list1) {
            sum = list1->val + carry;
            carry = sum/10;
            newnode = new ListNode(sum % 10);
            
            current->next = newnode;
            current = current->next;
            list1 = list1->next;
        }
        
        while(list2) {
            sum = list2->val + carry;
            carry = sum/10;
            newnode = new ListNode(sum % 10);
            
            current->next = newnode;
            current = current->next;
            list2 = list2->next; 
        }
        
        if(carry == 1) {
            current->next = new ListNode(1);
        }
        
        current = head;
        
        head = head->next;
        
        delete current;
        
        return head;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
