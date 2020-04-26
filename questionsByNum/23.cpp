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
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        ListNode pn = ListNode(0, l1);
        ListNode qn = ListNode(0, l2);
        ListNode* p = &pn;
        l1 = p;
        ListNode* q = &qn;
        ListNode* t;
        while(p->next && q->next){
            if(p->next->val > q->next->val){
                t = p->next;
                p->next = q->next;
                q->next = p->next->next;
                p->next->next = t;
            }
            else{
                p = p->next;
            }
        }
        if(q->next){
            p->next = q->next;
        }
        return l1->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        for(int i = 1; i < lists.size(); ++i){
            lists[0] = merge(lists[0], lists[i]);
        }
        return lists[0];
    }
};

//分治法
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
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        ListNode pn = ListNode(0, l1);
        ListNode qn = ListNode(0, l2);
        ListNode* p = &pn;
        l1 = p;
        ListNode* q = &qn;
        ListNode* t;
        while(p->next && q->next){
            if(p->next->val > q->next->val){
                t = p->next;
                p->next = q->next;
                q->next = p->next->next;
                p->next->next = t;
            }
            else{
                p = p->next;
            }
        }
        if(q->next){
            p->next = q->next;
        }
        return l1->next;
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int h){
        int mid = (l+h)/2;
        if(l == h) return lists[l];
        if(l > h) return NULL;
        return (mergeTwoList(merge(lists, l, mid), merge(lists, mid+1, h)));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        return merge(lists, 0, lists.size()-1);
    }
};