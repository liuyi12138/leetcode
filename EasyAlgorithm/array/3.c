//暴力翻转，每次挪动k的数的位置 空间复杂度为 O(1) 
void rotate(int* nums, int numsSize, int k){
    if(numsSize > 1 && k != 0){
        int temp;
        k = k % numsSize;
        int a = 0;
        if(k!=0) a = numsSize % k;
        int count = 0;
        while(k!=0 && (count+2)*k <= numsSize){
            for(int i = 0; i < k; ++i){
                temp = nums[numsSize-1-k*count-i];
                nums[numsSize-1-k*count-i] = nums[numsSize-1-k*count-i-k];
                nums[numsSize-1-k*count-i-k] = temp;
            }
            count++;
        }
        for(int i = 0; i < a; ++i){
            for(int j = 0; j < k; ++j){
                temp = nums[a-i-1+j];
                nums[a-i-1+j] = nums[a-i+j];
                nums[a-i+j] = temp;
            }
        }
    }
}

//三次数组逆序实现翻转
void reverse(int *a, int l, int h)
{
    for(int i = 0; i < (h - l + 1) / 2; i++){
        int t = a[l + i];
        a[l + i] = a[h - i];
        a[h - i] = t;
    }
}
void rotate(int* nums, int numsSize, int k){
    if(!nums || numsSize == 0)
        return;
    k = k % numsSize;
    reverse(nums, 0, numsSize - 1 - k);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}