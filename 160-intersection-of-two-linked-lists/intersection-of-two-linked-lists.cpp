class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int t1 = 1;
        int t2 = 1;
        ListNode* f1 = headA;
        ListNode* f2 = headB;
        while(f1->next){
            f1 = f1->next;
            t1++;
        }
        while(f2->next){
            f2= f2->next;
            t2++;
        }
        f1 = headA;
        f2 = headB;
        ListNode* res = nullptr;
        int i = 0;
        int diff = abs(t1-t2);
        if(t1>t2){
            while(i<diff){
                f1 = f1->next;
                i++;
            }
            while(f1!=nullptr && f2!=nullptr){
                if(f1==f2){
                    res = f1;
                    break;
                }
                f1 = f1->next;
                f2 = f2->next;
            }
        }
        else if(t1<t2){
            while(i<diff){
                f2 = f2->next;
                i++;
            }
            while(f2!=nullptr && f1!=nullptr){
                if(f1==f2){
                    res = f2;
                    break;
                }
                f1 = f1->next;
                f2 = f2->next;
            }
        }
        else{
            while(f1!=nullptr && f2!=nullptr){
                if(f1==f2){
                    res = f1;
                    break;
                }
                f1 = f1->next;
                f2 = f2->next;
            }
        }
        return res;

    }
};