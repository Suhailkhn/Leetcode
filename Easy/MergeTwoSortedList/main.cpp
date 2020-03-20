#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
        
    if(!(l1 || l2))             // Both lists are empty
        return head;
    else if(!l1)                // First list is empty
        return l2;
    else if(!l2)                // Second list is empty
        return l1;
        
    ListNode* current1 = l1;       // To Pass through first list
    ListNode* current2 = l2;       // To Pass through second list
        
    ListNode* newnode = new ListNode(-1);         // Used to generate new nodes
    ListNode* current = new ListNode(-1);         // Used to wire up nodes of the new list
        
        
    // Create the first node
    if(current1->val <= current2->val) {
        current->val = current1->val;
        current1 = current1->next;
    } else {
        current->val = current2->val;
        current2 = current2->next;
    }
        
    head = current;
        
    // Remaining Nodes
    while((current1 != nullptr) && (current2 != nullptr)) {
        newnode = new ListNode(-1);
        current->next = newnode;
        
        if(current1->val <= current2->val) {
            newnode->val = current1->val;
            current1 = current1->next;
        } else {
            newnode->val = current2->val;
            current2 = current2->next;
        }
        
        current = current->next;
    }
        
    // Second list is over first.
    while(current1) {
        newnode = new ListNode(-1);
        current->next = newnode;
        newnode->val = current1->val;
        current1 = current1->next;
        current = current->next;
    }
        
    // First list is over first.
    while(current2) {
        newnode = new ListNode(-1);
        current->next = newnode;
        newnode->val = current2->val;
        current2 = current2->next;
        current = current->next;
    }
        
    return head;
}

int main(int argc, char **argv)
{
	ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(4);
    
    l1->next = l2;
    l2->next = l3;
    
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(4);
    
    p1->next = p2;
    p2->next = p3;
    
    ListNode* head = mergeTwoLists(l1, p1);
    
    while(head) {
        std::cout << head->val << "\t";
        head = head->next;
    }
    
	return 0;
}
