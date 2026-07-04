class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> freq;
        while(headA){
            freq.insert(headA);
            headA = headA->next;
        }
        while(headB){
           if(freq.count(headB)) return headB;
           headB = headB->next;
        }
        return nullptr;
    }
};