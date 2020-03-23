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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        if(!head->next) return true;
        ListNode* p = head;
        int count = 0;
        while(p){
            count++;
            p = p->next;
        }
        stack<int> s;
        p = head;
        int k = count/2;
        while(k > 0){
            s.push(p->val);
            p = p->next;
            k--;
        }
        if(count % 2 == 1)
            p = p->next;
        while(p){
            if(p->val != s.top())
                return false;
            s.pop();
            p = p->next;
        }
        return true;
    }
};