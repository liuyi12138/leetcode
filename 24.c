/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if(!head || !head->next) return head;
    struct ListNode* p = NULL;
    struct ListNode* q = head;
    struct ListNode* r = head->next;
    struct ListNode* temp;
    head = head->next;
    while(q && r){
        temp = r->next;
        q->next = temp;
        r->next = q;
        if(p) p->next = r;
        p = q;
        q = temp;
        if(!temp) break;
        r = q->next;
    }
    return head;
}