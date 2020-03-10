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
    int dfs(TreeNode* root, int depth){
        if(!root) return depth-1;
        int leftDepth = dfs(root->left, depth+1);
        int RightDepth = dfs(root->right, depth+1);
        int diameter = leftDepth + RightDepth - 2*depth;
        if(diameter > maxDiameter) maxDiameter = diameter;
        return max(leftDepth, RightDepth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root, 0);
        return maxDiameter;
    }
private:
    int maxDiameter = 0;
};