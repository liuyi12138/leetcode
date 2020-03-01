bool canJump(int* nums, int numsSize){
    bool arrive[numsSize];
    memset(arrive, false, numsSize);
    arrive[0] = true;
    for(int i = 0; i < numsSize; ++i){
        if(arrive[i]){
            if(i + nums[i] >= numsSize - 1)
                return true;
            else{
                for(int j = 1; j <= nums[i]; ++j)
                    arrive[i+j] = true;
            }
        }
    }
    return arrive[numsSize-1];
}

//实际上不需要备忘录，只需要记录能到达的最远位置就可以
bool canJump(int* nums, int numsSize){
    int max = 0;
    for(int i = 0; i < numsSize; ++i){
        if(i > max) return false;
        max = max > i + nums[i] ? max : i + nums[i];
    }
    return true;
}

