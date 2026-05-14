class Solution {
public:
#define null NULL
#define node ListNode

    void reverse(ListNode* ptr, int size){
        ListNode* curr = ptr;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        int i = 0;
        while(i<size){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        return;
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode* left = head;
        ListNode* right = NULL;
        ListNode* prevLeft = NULL;
        ListNode* nextLeft = NULL;
        ListNode* res = NULL;
        if(head==NULL) return NULL;
        while(true){
            right = left;
            for(int i =0; i<2-1; i++){
                if(right==NULL) break;
                right = right->next;
            }
            if(right)
            {
                if(res==NULL) res = right;
                nextLeft = right->next;
                reverse(left,2);
                if(prevLeft==NULL) prevLeft = left;
                prevLeft->next = right;
                prevLeft = left;
                left = nextLeft;
            }
            else{
                if(prevLeft){
                    prevLeft->next = left;
                }
                if(res==NULL)
                res = left;
                break;
            }
        }
        return res;
    }
};