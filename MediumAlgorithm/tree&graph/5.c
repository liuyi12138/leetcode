/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void getAllNode(struct TreeNode* root, int* count, int** nums, int k){
    if(root && *count < k){
        getAllNode(root->left, count, nums, k);
        (*nums)[*count] = root->val;
        *count += 1;
        getAllNode(root->right, count, nums, k);
    }
}

int kthSmallest(struct TreeNode* root, int k){
    int* nums = (int*)malloc(10000*sizeof(int));
    int count = 0;
    getAllNode(root, &count, &nums, k);
    return nums[k-1];
}

