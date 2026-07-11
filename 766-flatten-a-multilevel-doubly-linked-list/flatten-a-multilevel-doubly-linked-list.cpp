class Solution {
public:
    Node* depth(Node*& head){
        Node* curr = head;
        Node* down = nullptr;
        Node* next = nullptr;
        Node* tail = curr;
        while(curr!=nullptr){
            if(curr->child!=nullptr) {
                down = depth(curr->child);
                tail = down;
                next = curr->next;
                curr->next = curr->child;
                curr->child->prev = curr;
                down->next = next;
                if(next!=nullptr) next->prev = down;
                curr->child = nullptr;
                curr = next;
                
            }
            else {
                tail = curr;
                curr = curr->next ; 
            }
            
        }
        return tail;
    }
    Node* flatten(Node* head) {
        if(head==nullptr) return nullptr;
        Node* curr = head;
        Node* down = nullptr;
        Node* next = nullptr;
        while(curr!=nullptr) {
            if(curr->child!=nullptr) {
                down = depth(curr->child);
                next = curr->next;
                curr->next = curr->child;
                curr->child->prev = curr;
                down->next = next;
                if(next!=nullptr) next->prev = down;
                curr->child = nullptr;
                curr = next;
            }
            else   curr = curr->next;
            
        }
        return head;
    }
};