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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* now;
        while(!q.empty()){
            vector<int> vals;
            int levelSize = q.size();
            for(int i = 0; i < levelSize; ++i){
                now = q.front();
                q.pop();
                vals.push_back(now->val);
                if(now->left) q.push(now->left);
                if(now->right) q.push(now->right);
            }
            res.push_back(vals);
        }
        return res;
    }
};

class Solution {
public:
    void dfs(TreeNode* root, vector<vector<int>>& res, int level){
        if(!root) return;
        if(res.size() < level){
            vector<int> temp;
            res.push_back(temp);
        }
        res[level-1].push_back(root->val);
        dfs(root->left, res, level+1);
        dfs(root->right, res, level+1);
        return;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        dfs(root, res, 1);
        return res;
    }
};