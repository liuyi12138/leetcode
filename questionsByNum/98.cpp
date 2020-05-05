/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidNode(TreeNode* root, long int minVal, long int maxVal){
        if(!root) return true;
        if(root->val <= minVal || root->val >= maxVal) return false;
        return isValidNode(root->right, root->val, maxVal) & isValidNode(root->left, minVal, root->val);
    }

    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return isValidNode(root->right, root->val, LONG_MAX) & isValidNode(root->left, LONG_MIN, root->val);
    }
};