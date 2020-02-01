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


bool isPalindrome(struct ListNode* head){
    if(!head || !head->next) return true;
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* l1 = head;
    struct ListNode* l2 = reverseList(slow->next);
    slow->next = NULL;
    while(l1 && l2){
        if(l1->val != l2->val) return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return true;
}

