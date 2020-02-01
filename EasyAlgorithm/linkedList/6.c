/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(!head) return false;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while(fast && fast->next){
        if(slow->next == fast->next->next) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}