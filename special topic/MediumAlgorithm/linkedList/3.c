/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = 0;
    int lenB = 0;
    struct ListNode* p = headA;
    while(p){
        p = p->next;
        lenA++;
    }
    p = headB;
    while(p){
        p = p->next;
        lenB++;
    }
    int step;
    if(lenA > lenB){
        step = lenA - lenB;
        while(headA && step > 0){
            headA = headA->next;
            step--;
        }
    }
    else{
        step = lenB - lenA;
        while(headB && step > 0){
            headB = headB->next;
            step--;
        }        
    }
    while(headA){
        if(headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}