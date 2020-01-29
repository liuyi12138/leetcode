/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void reverse(int* nums, int numsSize){
    int temp;
    for(int i = 0; i < numsSize/2; ++i){
        temp = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = temp;
    }
}


int* plusOne(int* digits, int digitsSize, int* returnSize){
    int* nums = (int*)malloc((digitsSize+1)*sizeof(int));
    reverse(digits, digitsSize);
    *returnSize = digitsSize;
    int flag = 0;
    if(digits[0] == 9){
        nums[0] = 0;
        flag = 1;
    }
    else{
        nums[0] = digits[0] + 1;
    }
    for(int i = 1; i < digitsSize; ++i){
        if(flag){
            if(digits[i] == 9){
                nums[i] = 0;
                flag = 1;
            }
            else{
                flag = 0;
                nums[i] = digits[i] + 1;
            }
        }
        else{
            nums[i] = digits[i];
        }
    }
    if(flag == 1){
        nums[digitsSize] = 1;
        *returnSize = digitsSize + 1;
    }
    reverse(nums, digitsSize + flag);
    return nums;
}

