#include <iostream>
#include <vector>
#include <unordered_map>

struct Node {
    int key, value;
    Node* next;
    Node* prev;
    Node() {next = nullptr; prev = nullptr;}
    Node(int key, int value)
        : key{key}, value{value} , next{nullptr}, prev{nullptr} {}
    static void add_to_head(Node* &head, Node* node) {
        head->prev = node;
        node->next = head;
        head = node;
        node->prev = nullptr;
    }
};

class LRUCache {
public:
    std::unordered_map<int, Node*> key_node;
    int current_cap, max_cap;
    
    Node* head;
    Node* tail;
    
    LRUCache(int capacity) {
        max_cap = capacity;
        current_cap = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if(key_node.find(key) == key_node.end())
            return -1;
        
        Node* current_node = key_node[key];
        
        if(current_node != head) {
            current_node->prev->next = current_node->next;
            if(current_node->next) 
                current_node->next->prev = current_node->prev;
            else {
                tail = current_node->prev;
            }
            
            Node::add_to_head(head, current_node);
        }
        
        return current_node->value;
    }
    
    void put(int key, int value) {
        if(!head) {                         // First input
            head = new Node(key, value);
            tail = head;
            ++current_cap;
            key_node[key] = head;
        } else if(key_node.find(key) != key_node.end()){        // Set value
            Node* current_node = key_node[key];
            
            if(current_node != head) {
                current_node->prev->next = current_node->next;
                if(current_node->next)
                    current_node->next->prev = current_node->prev;
                else
                    tail = current_node->prev;

                Node::add_to_head(head, current_node);
            }
            
            current_node->value = value;
        } else if(current_cap < max_cap) {              // Cache is not full
            Node::add_to_head(head, new Node(key, value));
            ++current_cap;
            key_node[key] = head;
        } else {                                        // Cache full. Element has to be replaced.
            Node::add_to_head(head, new Node(key, value));
            tail->prev->next = nullptr;
            Node* temp = tail;
            
            auto it = key_node.find(tail->key);
            key_node.erase(it);
            delete temp;
            
            tail = tail->prev;
            key_node[key] = head;
        }
    }

    void print() {
        Node* current = head;
        while(current) {
            std::cout << "\n" << current->key << "\t" << current->value;
            current = current->next;
        }
    }
};

int main(int argc, char **argv)
{
	LRUCache cache {2};
//    cache.put(1, 107);
//    cache.put(2, 218);
//    cache.put(3, 345);
//    cache.print();
//    std::cout << "\n\n\n";
//    
//    cache.put(4, 472);
//    cache.print();
//    std::cout << "\n\n\n";
//    
//    cache.get(2);
//    
//    cache.put(5, 531);
//    cache.put(6, 679);
//    //cache.put(7, 793);
//    cache.print();
//    std::cout << "\n\n\n";
//    
//    cache.put(6, 627);
//    cache.print();
//    std::cout << "\n";


    cache.put(2, 1);
    cache.put(1, 1);
    cache.print();
    std::cout << "\n\n\n";
    //std::cout << "\n" << cache.get(1) << "\n";
    cache.put(2, 3);
    cache.print();
    std::cout << "\n\n\n";
    //std::cout << "\n" << cache.get(2) << "\n";
    cache.put(4, 1);
    cache.print();
    std::cout << "\n\n\n";
    
    std::cout << "\n" << cache.get(1) << "\n";
    std::cout << "\n" << cache.get(2) << "\n";
    //std::cout << "\n" << cache.get(4) << "\n";
    
    cache.print();
    std::cout << "\n";

	return 0;
}