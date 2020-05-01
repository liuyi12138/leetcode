/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode np = ListNode(0, l1);
        ListNode nq = ListNode(0, l2);
        ListNode* p = &np;
        ListNode* q = &nq;
        ListNode* t;
        l1 = p;
        while(p->next && q->next){
            if(p->next->val > q->next->val){
                t = p->next;
                p->next = q->next;
                q->next = q->next->next;
                p->next->next = t;
            }
            else{
                p = p->next;
            }
        }
        if(q->next){
            p->next = q->next;
        }
        return l1->next;
    }
};