class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        for(int i = 0; i<=n; i++){
            fast = fast->next;
        }
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow->next!=nullptr && slow->next->next!=nullptr){
            slow->next = slow->next->next;
        }
        else{
            slow->next = nullptr;
        }
        return dummy->next;
    }
};