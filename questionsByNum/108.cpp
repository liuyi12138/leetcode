class Solution {
public:
    TreeNode* buileTree(vector<int>& nums, int l, int r){
        if(l > r) return NULL;
        int mid = (l+r)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buileTree(nums, l, mid-1);
        root->right = buileTree(nums, mid+1, r);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buileTree(nums, 0, nums.size()-1);
    }
};