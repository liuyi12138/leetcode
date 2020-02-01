/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(!head || !head->next) return head;
    struct ListNode* p = head;
    struct ListNode* q = head->next;
    struct ListNode* r;
    p->next = NULL;
    while(q){
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
}

