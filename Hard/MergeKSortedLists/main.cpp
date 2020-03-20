#include <stdio.h>

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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(!n)
            return nullptr;
        
        ListNode* newlist;
        int j {0};
        
        while(j < n && lists[j] == nullptr) {   // Find the first non empty list
            ++j;
        }
        newlist = j < n ? lists[j] : nullptr;
        
        int i {j+1};
        while(i < n) {                      // Merge all non empty lists
            if(lists[i])
                newlist = merge(newlist, lists[i]);
            ++i;
        }
        return newlist;
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
