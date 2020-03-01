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
void reverse(int* level, int levelSize){
    int l = 0;
    int h = levelSize-1;
    int temp;
    while(l<h){
        temp = level[l];
        level[l] = level[h];
        level[h] = temp;
        ++l;
        --h;
    }
}


struct queue{
    int level;
    struct TreeNode* data;
    struct queue* next;
};

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(100*sizeof(int*));
    int levelCount = 0;
    int* colSize = (int*)malloc(100*sizeof(int));
    memset(colSize, 0, 100*sizeof(int));
    struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
    struct queue* end = queue;
    queue->data = root;
    queue->level = 1;
    queue->next = NULL;
    while(queue && queue->data){
        if(queue->data->left){
            struct queue* left = (struct queue*)malloc(sizeof(struct queue));
            left->data = queue->data->left;
            left->level = queue->level + 1;
            left->next = NULL;
            end->next = left;
            end = end->next;
        }
        if(queue->data->right){
            struct queue* right = (struct queue*)malloc(sizeof(struct queue));
            right->data = queue->data->right;
            right->level = queue->level + 1; 
            right->next = NULL;
            end->next = right;
            end = end->next;
        }
        if(queue->level > levelCount){
            int* temp = (int*)malloc(256*sizeof(int));
            temp[0] = queue->data->val;
            colSize[levelCount] = 1;
            result[levelCount] = temp;
            levelCount++;
        }
        else{
            result[levelCount-1][colSize[levelCount-1]] = queue->data->val;
            colSize[levelCount-1] += 1;
        }
        queue = queue->next;
    }
    *returnColumnSizes = colSize;
    *returnSize = levelCount;
    for(int i = 0; i < levelCount; ++i){
        if(i % 2 == 1)
            reverse(result[i], colSize[i]);
    }
    return result;
}

