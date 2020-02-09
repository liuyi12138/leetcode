bool increasingTriplet(int* nums, int numsSize){
    if(numsSize < 3) return false;
    int minnum[2];
    minnum[0] = INT_MAX;
    minnum[1] = INT_MAX;
    for(int i = 0; i < numsSize; ++i){
        if(nums[i] > minnum[1])
            return true;
        else if(nums[i] < minnum[0]){
            minnum[0] = nums[i];
        }
        else if(nums[i] > minnum[0] && nums[i] < minnum[1]){
            minnum[1] = nums[i];
        }
    }
    return false;
}

