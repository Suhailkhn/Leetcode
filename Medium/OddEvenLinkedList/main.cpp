#include <iostream>

/*
    eg. 1->2->3->4->5->6
    When we swap 2 and 3 we will have 1->3->2......
    When we swap 5 we don't want to swap it with 1 but with 3.
    Hence we need odd_section_end pointer (which in this situation will be pointing to 3) to know after which node to append.
    even_section_start is needed to wire 5->2
    even_section_end is needed to wire 4->6 when swapping 5 so we don't lose access to 6 and elements to its right.
    
    
    Hopefully this cleared the usage of all the pointers used. The 6 swaps are fairly easy to follow 
    and just do what the above lines say.
    
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        if(!head->next)
            return head;
        
        ListNode* even_section_start = head->next;
        ListNode* even_section_end = head;
        ListNode* odd_section_end = head;
        ListNode* current_node = head->next;
        
        bool swap{false};
        while(current_node) {
            if(swap) {
                even_section_end->next = current_node->next;
                
                if(current_node->next)
                    even_section_end = current_node->next;      // Don't wanna do this for the last node in list 
                                                                //otherwise even_section_end will become nullptr and 
                                                                //then you cannot do current_node = even_section_end->next;
                current_node->next = even_section_start;
                
                odd_section_end->next = current_node;
                odd_section_end = current_node;
                
                current_node = even_section_end->next;
            } else {
                current_node = current_node->next;
                even_section_end = even_section_end->next;
                swap = true;
            }

        }
        
        return head;
    }

int main(int argc, char **argv)
{
	ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    
    ListNode* head = l1;
    
    ListNode* result = oddEvenList(head);
    
    while(result) {
        std::cout << result->val << "\t";
        result = result->next;
    }
    std::cout << "\n";
    
}
