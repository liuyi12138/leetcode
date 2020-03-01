/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void InsertNode(struct TreeNode* root, int target){
    struct TreeNode* temp = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    temp->val = target;
    temp->left = NULL;
    temp->right = NULL;
    struct TreeNode* p = root;
    while(p){
        if(temp->val > p->val){
            if(!p->right){
                p->right = temp;
                break;
            }
            else p = p->right;
        }
        else{
            if(!p->left){
                p->left = temp;
                break;
            }
            else p = p->left;
        }
    }   
}

void InsertMid(struct TreeNode* root, int* nums, int l, int h){
    if(l == h)  InsertNode(root, nums[l]);
    else if(l == h-1){
        InsertNode(root, nums[h]);
        InsertNode(root, nums[l]);
    }
    else if(l < h){
        int mid = (l + h) / 2;
        InsertNode(root, nums[mid]);
        InsertMid(root, nums, l, mid-1);
        InsertMid(root, nums, mid+1, h);
    }

}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize == 0) return NULL;
    int mid = numsSize / 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = NULL;
    root->right = NULL;
    InsertMid(root, nums, 0, mid-1);
    InsertMid(root, nums, mid+1, numsSize-1);
    return root;
}

