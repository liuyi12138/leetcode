/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isvalidBST(struct TreeNode* root, long int minval, long int maxval){
    if(!root) return true;
    if(root->val <= minval || root->val >= maxval) return false;
    return isvalidBST(root->left, minval, root->val) & isvalidBST(root->right, root->val, maxval);
}

bool isValidBST(struct TreeNode* root){
    if(!root) return true;
    return isvalidBST(root, LONG_MIN, LONG_MAX);
}

