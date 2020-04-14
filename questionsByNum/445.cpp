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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int flag = 0;
        int sum = 0;
        ListNode* head = new ListNode(1);
        while(!s1.empty() || !s2.empty()){
            sum = flag;
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            flag = sum / 10;
            sum = sum % 10;
            ListNode* temp = new ListNode(sum);
            temp->next = head->next;
            head->next = temp;
        }
        if(flag)
            return head;
        return head->next;
    }
};