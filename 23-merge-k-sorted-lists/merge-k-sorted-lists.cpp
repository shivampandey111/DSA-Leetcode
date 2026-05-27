class Solution {
public:

    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // Put first node of every list into heap
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(!pq.empty()) {

            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            // Push next node of same list
            if(curr->next != NULL) {
                pq.push(curr->next);
            }
        }

        return dummy->next;
    }
};