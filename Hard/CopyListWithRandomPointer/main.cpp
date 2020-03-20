#include <stdio.h>

// Time  Complexity : O(n)
// Space Complexity : O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        
        std::unordered_map<Node*, int> og_list_indices;     // Stores index of nodes in original list
        
        std::vector<int> random_index;                      // Mapping of index pointed by random pointer. 
        // random_index[i] = j means ith node's random pointer is to be connected to jth node
        
        std::unordered_map<int, Node*> new_list_indices;    // Stores address of node at each index in new list
        
        Node* current_old = head;
        og_list_indices[head] = 0;
        int i = 0, j = 0;
        
        // Create new list without wiring random pointer
        Node* new_head = new Node(head->val, nullptr, nullptr);
        new_list_indices[0] = new_head;
        Node* current_new = new_head;
        
        while(current_old->next) {
            current_old = current_old->next;
            og_list_indices[current_old] = ++i;
            
            current_new->next = new Node(current_old->val, nullptr, nullptr);
            current_new = current_new->next;
            new_list_indices[++j] = current_new;
        }
        
        // Create mapping of random pointer
        current_old = head;
        int index;
        while(current_old) {
            if(current_old->random)
                index = og_list_indices[current_old->random];
            else
                index = -1;                     // Indicates random pointer is to be kept null
            random_index.push_back(index);
            
            current_old = current_old->next;
        }
        
        // Wire up random pointer of new list
        current_new = new_head;
        index = 0;
        while(current_new) {
            if(random_index[index] != -1) {
                current_new->random = new_list_indices[random_index[index]];
            }
            current_new = current_new->next;
            ++index;
        }
        
        return new_head;
        
    }
};

int main(int argc, char **argv)
{
	printf("hello world\n");
	return 0;
}
