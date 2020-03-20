#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        // Merge by inserting elements of list 2 at their proper position in list 1
        ListNode* current1 = list1;
        ListNode* current2 = list2;    
        ListNode* prev1 = nullptr;
        
        while(list2) {          // while there are elements in list 2
            if(current1) {
                if(current1->val <= current2->val) { // move ahead if you are not less than 
                                                     // the current element of list 1
                    prev1 = current1;
                    current1 = current1->next;
                } else {        // Insert before current element of list 1
                    list2 = current2->next;     // Don't lose pointer to the second list
                
                    if(prev1 == nullptr) {      // New head
                        current2->next = list1;
                        list1 = current2;
                        prev1 = current2;
                    } else {
                        current2->next = prev1->next;
                        prev1->next = current2;
                        prev1 = current2;
                    }
                
                    current2 = list2;       // Next element for comparison
                }
            } else {            // Elements remaining are greater than list 1. Simply append
                prev1->next = list2;
                break;
            }
        }
        
        return list1;
    }
    
    ListNode* split(ListNode* head, int length) {
        // Divide the list into two halves
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while(fast && fast->next) {     // When the fast pointer reaches/crosses the end
                                        // the slow pointer will be in the middle 
                                        // i.e end of the first list
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list2 = slow->next;
        slow->next = nullptr;
        return list2;
    }
    
    ListNode* mergesort(ListNode* head, int length) {
        if(length <= 1)
            return head;
        
        ListNode* list1 = head; 
        ListNode* list2 = split(head, length);
        
        list1 = mergesort(list1, length/2);
        list2 = mergesort(list2, length - length/2);
        return merge(list1, list2);
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head)
            return nullptr;
        
        int n {0};
        ListNode* current = head;
        while(current) {
            ++n;
            current = current->next;
        }
        
        head = mergesort(head, n);
        return head;
    }

};


int main(int argc, char **argv)
{
	ListNode* a1 = new ListNode(7);
    ListNode* a2 = new ListNode(3);
    ListNode* a3 = new ListNode(9);
    ListNode* a4 = new ListNode(5);
    ListNode* a5 = new ListNode(2);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    
    ListNode* head = sortList(a1);
    while(head) {
        std::cout << head->val << "\t";
        head = head->next;
    }
    
	return 0;
}
