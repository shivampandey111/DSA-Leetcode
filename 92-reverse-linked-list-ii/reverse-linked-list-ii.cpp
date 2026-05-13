/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        if(head==NULL) return NULL;
        ListNode* first = head;
   
        ListNode* start = NULL;
       
        
        int i = 1;
        while(i<left){
            start = first;
            first = first->next;
            i++;
        }
        
        ListNode* curr = first;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        int time = right - left;
        int j = 0;
        while(j<=time){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            j++;
        }
        
        
        first->next = curr;
        if(start){
            start->next = prev;
            return head;
        }
        return prev;
    }
};