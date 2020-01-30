/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int ergodic(int* nums, int l, int h, int target, int* result){
    int med = (l + h) / 2;
    for(int i = l; i <= med; ++i){
        for(int j = med + 1; j <= h; ++j){
            if(target == nums[i] + nums[j]){
                result[0] = i;
                result[1] = j;
                return 1;
            }
        }
    }
    return 0;
}

int find2Sum(int* nums, int l, int h, int target, int* result){
    if(h <= l)
        return 0;
    if(h == l + 1){
        if(target == nums[l] + nums[h]){
            result[0] = l;
            result[1] = h;
            return 1;
        }
        return 0;
    }
    int med = (l + h) / 2;
    int leftRes = find2Sum(nums, l, med, target, result);
    int rightRes = find2Sum(nums, med, h, target, result);
    if(!leftRes && !rightRes)
        return ergodic(nums, l, h, target, result);
    else
        return 1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 0;
    if(numsSize <= 1) return NULL;
    int* result = (int*)malloc(2*sizeof(int));
    if(find2Sum(nums, 0, numsSize-1, target, result)){
        *returnSize = 2;
    }
    else{
        *returnSize = 0;
    }
    return result;
}

