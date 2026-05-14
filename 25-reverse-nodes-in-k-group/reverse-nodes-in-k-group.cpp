class Solution {
public:
#define null NULL
#define node ListNode
    void reverse(node* ptr, int size){
        node* curr = ptr;
        node* next = null; 
        node* prev = null;
        int num = 0;
        while(num<size){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            num++;
        }
        return;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        node* left = head;
        node* right= null;
        node* prevLeft = null;
        node* nextLeft = null;
        node* res = null;
        while(true){
            right = left;
            for(int i = 0; i<k-1; i++){
                if(right==null) break;
                right= right->next;
            }
            if(right){
                if(res==null) res = right;
                nextLeft = right->next;
                reverse(left, k);
                if(prevLeft) prevLeft->next = right;
                prevLeft = left;
                left = nextLeft;
            }
            else{
                if(prevLeft) prevLeft->next = left;
                if(res==null) res = left;
                break;
            }
        }
        return res;
    }
};