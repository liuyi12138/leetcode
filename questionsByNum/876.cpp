class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = fast->next;
        while(slow && fast && slow->next && fast->next){
            temp = fast->next;
            fast = fast->next->next;
            slow = slow->next;
        }
        if(!temp)
            return slow->next;
        else
            return slow;
    }
};