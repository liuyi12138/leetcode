


typedef struct {
    int* oldnums;
    int* newnums;
    int numsSize;
} Solution;


Solution* solutionCreate(int* nums, int numsSize) {
    Solution* s = (Solution*)malloc(sizeof(Solution));
    int* newnums = (int*)malloc(numsSize*sizeof(int));
    for(int i = 0; i < numsSize; ++i){
        newnums[i] = nums[i];
    }
    s->oldnums = nums;
    s->numsSize = numsSize;
    s->newnums = newnums;
    return s;
}
/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int* retSize) {
    *retSize = obj->numsSize;
    return obj->oldnums;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int* retSize) {
    // srand(time(NULL));
    int index,temp;
    int* newnums = obj->newnums;
    *retSize = obj->numsSize;
    for(int i = 0; i < obj->numsSize; ++i){
        index=rand()%(obj->numsSize-i)+i;
        if(index != i){
            temp = newnums[i];
            newnums[i] = newnums[index];
            newnums[index] = temp;
        }
    }
    return newnums;
}

void solutionFree(Solution* obj) {
    free(obj->newnums);
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int* param_1 = solutionReset(obj, retSize);
 
 * int* param_2 = solutionShuffle(obj, retSize);
 
 * solutionFree(obj);
*/