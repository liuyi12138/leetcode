/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int compare(void* a, void*b){
     return *(int*)a - *(int*)b;
 }

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    if(numsSize == 0 || nums[0] > 0 || nums[numsSize-1] < 0) return NULL;
    int** result = (int**)malloc((numsSize) * (numsSize) * sizeof(int*));
    int* columnSizes = (int*)malloc((numsSize) * (numsSize) * sizeof(int));
    *returnColumnSizes = columnSizes;
    for(int i = 0; i < numsSize-2; ++i){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int l = i+1;
        int h = numsSize-1;
        int target = 0 - nums[i];
        while(l < h){
            if(nums[l] + nums[h] == target){
                int* temp = (int*)malloc(3*sizeof(int));
                temp[0] = nums[i];
                temp[1] = nums[l];
                temp[2] = nums[h];
                result[*returnSize] = temp;
                columnSizes[*returnSize] = 3;
                *returnSize += 1;
                while((l < h) && (nums[l] == nums[l + 1]))
                    l++;
                l++;
                while ((l < h) && (nums[h] == nums[h - 1]))
                    h--;
            }
            else if(nums[l] + nums[h] < target) l++;
            else h--;
        }
    }
    return result;
}