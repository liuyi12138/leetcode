/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = l1;
    struct ListNode* pre;
    int flag = 0;
    int temp = 0;
    while(l1 && l2){
        temp = l1->val + l2->val + flag;
        flag = temp / 10;
        l1->val = (temp % 10);

        pre = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    pre->next = (l2 == NULL ? l1 : l2);
    while(pre->next){
        temp = pre->next->val + flag;
        flag = temp / 10;
        pre->next->val = (temp % 10);
        pre = pre->next;
    }
    if(flag){
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = 1;
        node->next = NULL;
        pre->next = node;
    }
    return head;
}

