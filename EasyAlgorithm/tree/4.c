/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 //此题更好的解法应该为队列
int maxDepth(struct TreeNode* root){
    if(!root) return 0;
    else if(!root->left && !root->right) return 1;
    int ld = maxDepth(root->left);
    int rd = maxDepth(root->right);
    return (ld > rd ? ld+1 : rd+1);
}

void getNode(struct TreeNode* root, int* returnSize, int** returnColumnSizes, int*** result, int depth, int index){
    // printf("depth%d index%d:%d\n",depth,index,root->val);
    if(index == 0){
        int size;
        if(depth > 20) size = 10;
        else size = pow(2,depth);
        int* resultd = (int*)malloc(size*sizeof(int));
        (*result)[depth] = resultd;
        (*returnColumnSizes)[depth+1] = 0;
    }
    if((root->left || root->right) && (*returnColumnSizes)[depth+1] == 0) *returnSize += 1;
    (*result)[depth][index] = root->val; 
    (*returnColumnSizes)[depth] += 1;
    if(root->left) getNode(root->left, returnSize, returnColumnSizes, result, depth+1, (*returnColumnSizes)[depth+1]);
    if(root->right) getNode(root->right, returnSize, returnColumnSizes, result, depth+1, (*returnColumnSizes)[depth+1]);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(!root) return NULL;
    *returnSize = 1;
    int max = maxDepth(root) + 1;
    int*** resultq = (int***)malloc(sizeof(int**));
    int** result = (int**)malloc(max*sizeof(int*));
    int* columnSizes = (int*)malloc(max*sizeof(int));
    *returnColumnSizes = columnSizes;
    columnSizes[0] = 0;
    *resultq = result;
    getNode(root, returnSize, returnColumnSizes, resultq, 0, 0);
    return result;
}

