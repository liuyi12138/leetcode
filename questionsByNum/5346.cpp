class Solution {
public:    
    bool isSubPathFlag(ListNode* head, TreeNode* root, bool flag){
        if(!checkSize(head, root)) return false; 
        if(head == NULL) return true;
        if(root == NULL) return false;
        if(root->val == head->val){
            bool result = isSubPathFlag(head->next, root->left, true) || isSubPathFlag(head->next, root->right, true);
            if(result) return true;
        }
        if(flag) return false;
        return isSubPathFlag(head, root->left, false) || isSubPathFlag(head, root->right, false);    
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        return isSubPathFlag(head, root, false);
    }
};