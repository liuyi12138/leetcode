/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //递归算法
int inordert(struct TreeNode* root, int* result, int count){
    if(!root) return count;
    count = inordert(root->left, result, count);
    result[count] = root->val;
    count++;
    count = inordert(root->right, result, count);
    return count;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* result = (int*)malloc(100*sizeof(int));
    int count = 0;
    count = inordert(root, result, 0);
    *returnSize = count;
    return result;
}

 //迭代算法 使用栈解决
struct stack{
    struct TreeNode** data;
    int top;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* result = (int*)malloc(100*sizeof(int));
    int count = 0;
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->data = (struct TreeNode**)malloc(10 * sizeof(struct TreeNode*));
    stack->top = 0;
    while(root || stack->top > 0){
        while(root){
            stack->data[stack->top] = root;
            stack->top += 1;
            root = root->left;
        }
        root = stack->data[stack->top-1];
        stack->top -= 1;
        result[count] = root->val;
        count++;
        root = root->right;
    }
    *returnSize = count;
    return result;
}
