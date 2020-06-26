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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* node = head;
        unordered_set<int> mset;
        mset.insert(head->val);
        while(node->next){
            if(mset.find(node->next->val) != mset.end()){
                node->next = node->next->next;
            }
            else{
                mset.insert(node->next->val);
                node = node->next;
            }
        }
        return head;
    }
};