int removeDuplicates(int* nums, int numsSize){
    if(numsSize <= 2)
        return numsSize;
    int count = 2;
    for(int i = 2; i < numsSize; ++i){
        if(nums[i] != nums[count-2]){
            nums[count] = nums[i];
            count++;
        }
    }
    return count;
}
