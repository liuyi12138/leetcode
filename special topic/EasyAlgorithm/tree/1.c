/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root){
    if(!root) return 0;
    else if(!root->left && !root->right) return 1;
    int ld = maxDepth(root->left);
    int rd = maxDepth(root->right);
    return (ld > rd ? ld+1 : rd+1);
}

