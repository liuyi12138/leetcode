/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if((s && !t) || (!s && t)) return false;
        if(s->val == t->val){
            if(isSameTree(s->left, t->left) & isSameTree(s->right, t->right))
                return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(isSameTree(s, t)) return true;
        if(s) return (isSubtree(s->left, t) | isSubtree(s->right, t));
        return (t == NULL);
    }
};