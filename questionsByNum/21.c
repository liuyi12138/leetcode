/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1) return l2;
    else if(!l2) return l1;
    struct ListNode* p = l1;
    struct ListNode* q = l2;
    struct ListNode* l3;
    struct ListNode* result;
    if(p->val < q->val){
        l3 = p;
        p = p->next;
    }
    else{
        l3 = q;
        q = q->next;
    }
    result = l3;
    while(p && q){
        if(p->val < q->val){
            l3->next = p;
            p = p->next;
        }
        else{
            l3->next = q;
            q = q->next;
        }
        l3 = l3->next;
    }
    if(p) l3->next = p;
    else l3->next = q;
    return result;
}