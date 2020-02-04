/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool compare(struct TreeNode* root1, struct TreeNode* root2){
    if(!root1 && !root2) return true;
    else if(root1 && !root2 || !root1 && root2) return false;
    else if(root1->val != root2->val) return false;
    else return (compare(root1->left, root2->right) && compare(root1->right, root2->left));
}

bool isSymmetric(struct TreeNode* root){
    if(!root) return true;
    return compare(root->left, root->right);
}
