/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* p = head;
    struct ListNode* q = head;
    for(int i = 0; i < n; ++i){
        q = q->next;
    }
    if(!q) return head->next;
    while(q->next){
        q = q->next;
        p = p->next;
    }
    p->next = p->next->next;
    return head;
}

