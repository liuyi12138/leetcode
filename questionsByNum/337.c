/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//递归的方法超时了
int getMax(int a, int b){
    int result = a > b ? a : b;
    return result;
}

int rob(struct TreeNode* root){
    if(!root) return 0;
    int res1 = root->val;
    if(root->left)
        res1 += rob(root->left->left) + rob(root->left->right);
    if(root->right)
        res1 += rob(root->right->left) + rob(root->right->right);
    int res2 = rob(root->left) + rob(root->right);
    return getMax(res1, res2);
}

//把信息存在node->val中
int getMax(int a, int b){
    int result = a > b ? a : b;
    return result;
}

int rob(struct TreeNode* root){
    if(!root) return 0;
    if(root->val < 0) return (0 - root->val);
    int res1 = root->val;
    if(root->left)
        res1 += rob(root->left->left) + rob(root->left->right);
    if(root->right)
        res1 += rob(root->right->left) + rob(root->right->right);
    int res2 = rob(root->left) + rob(root->right);
    int result = getMax(res1, res2);
    root->val = 0 - result;
    return result;
}