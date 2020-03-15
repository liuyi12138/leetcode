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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            if(!s.empty()){
                root = s.top();
                s.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        if(res.size() == 0)
            return NULL;
        if(res.size() == 1){
            TreeNode*r =new TreeNode(res[0]);
            return r;
        }
        int first = 0;
        int last = res.size()-1;
        return helper(res,first,last);
    }
    
    TreeNode* helper(vector<int>num,int first,int last){
        if(first>last){
            return NULL;
        }
        if(first==last){
            TreeNode* parent=new TreeNode(num[first]);
            return parent;
        }
        int mid=(first+last)/2;
        TreeNode*leftchild = helper(num,first,mid-1);
        TreeNode*rightchild = helper(num,mid+1,last);
        TreeNode *parent = new TreeNode(num[mid]);
        parent->left = leftchild;
        parent->right = rightchild;
        return parent;
    }

};