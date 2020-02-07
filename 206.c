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
    struct ListNode* q = p->next;
    struct ListNode* temp;
    p->next = NULL;
    while(p && q){
        temp = q->next;
        q->next = p;
        p = q;
        q = temp;
    }
    return p;
}