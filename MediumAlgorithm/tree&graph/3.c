/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//一开始就没有设计好，想着每次递归解决左右节点，结果过于复杂，主要在于数组切分很难调试
void buildChildTree(struct TreeNode* root, int* preorder, int preorderSize, int* prerootIndex, int* inorder, int inorderSize, int inrootIndex){
    if((*prerootIndex) == preorderSize - 1) return;
    int leftIndex = -1;
    for(int i = 0; i < inrootIndex; ++i){
        if(inorder[i] == preorder[(*prerootIndex) + 1]){
            leftIndex = i;
            (*prerootIndex) += 1;
            break; 
        }       
    }
    if(leftIndex >= 0){
        struct TreeNode* left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        left->val = inorder[leftIndex];
        left->left = NULL;
        left->right = NULL;
        root->left = left;
        buildChildTree(left, preorder, preorderSize, prerootIndex, inorder, inrootIndex, leftIndex);
    }

    if((*prerootIndex) == preorderSize - 1) return;
    int rightIndex = -1;
    for(int i = inrootIndex+1; i < inorderSize; ++i){
        if(inorder[i] == preorder[(*prerootIndex) + 1]){
            rightIndex = i;
            (*prerootIndex) += 1;
            break; 
        }       
    }
    if(rightIndex >= 0){
        struct TreeNode* right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        right->val = inorder[rightIndex];
        right->left = NULL;
        right->right = NULL;
        root->right = right;
        buildChildTree(right, preorder, preorderSize, prerootIndex, inorder+inrootIndex+1, inorderSize-inrootIndex-1, rightIndex-inrootIndex-1);
    }
    return;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if(preorderSize == 0) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;
    int inrootIndex;
    for(int i = 0; i < inorderSize; ++i){
        if(inorder[i] == preorder[0]){
            inrootIndex = i;
            break; 
        }       
    }
    int* prerootIndex = (int*)malloc(sizeof(int));
    *prerootIndex = 0;
    buildChildTree(root, preorder, preorderSize, prerootIndex, inorder, inorderSize, inrootIndex);
    return root;
}

//其实每次只要管一个节点就好了，递归就不应该想太多
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (inorderSize == 0) return NULL;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] != preorder[0]) continue;
        root->left = buildTree(preorder+1, i, inorder, i);
        root->right = buildTree(preorder+i+1, inorderSize-i-1, inorder+i+1, inorderSize-i-1);
        break;
    }
    return root;
}