/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //递归解法
class Solution {
public:
    bool isSameTree(TreeNode* l, TreeNode* r){
        if((l == NULL) ^ (r == NULL)) return false;
        if(!l && !r) return true;
        if(l->val != r->val) return false;
        return isSameTree(l->left, r->right) & isSameTree(l->right, r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSameTree(root->left, root->right);
    }
};

//迭代解法
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* t1 = q.front(); q.pop();
            TreeNode* t2 = q.front(); q.pop();
            if(!t1 && !t2) continue;
            if((!t1 || !t2) || t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};