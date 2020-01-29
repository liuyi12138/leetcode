// void moveZeroes(int* nums, int numsSize){
//     int count = 0;
//     int temp;
//     for(int i = 0; i < numsSize; ++i){
//         if(nums[i] != 0){
//             temp = nums[i];
//             nums[i] = nums[count];
//             nums[count] = temp;
//             count++;
//         }
//     }
// }

void moveZeroes(int* nums, int numsSize){
    int count = 0;
    for(int i = 0; i < numsSize; ++i){
        if(nums[i] != 0){
            nums[count] = nums[i];
            count++;
        }
    }
    for(int i = count; i < numsSize; ++i){
        nums[i] = 0;
    }
}

