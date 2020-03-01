//动态规划
int maxSubArray(int* nums, int numsSize){
    int max = nums[0];
    int sum = 0;
    for(int i = 0; i < numsSize; ++i){
        if(sum > 0){
            sum += nums[i];
        }
        else{
            sum = nums[i];
        }
        if(sum > max){
            max = sum;
        }
    }
    return max;
}


//分治法
int getMax(int a, int b, int c){
    if(a >= b && a >= c) return a;
    if(b >= a && b >= c) return b;
    return c;
}

int getMidRes(int* nums, int l, int h, int mid){
    int max = nums[mid] + nums[mid+1];
    int sum = nums[mid] + nums[mid+1];
    if(l == h-1) return max;
    for(int i = mid-1; i >= l; --i){
        sum += nums[i];
        if(sum > max)
            max = sum;
    }
    sum = max;
    for(int i = mid+2; i <= h; ++i){
        sum += nums[i];
        if(sum > max)
            max = sum;
    }
    return max;
}

int maxSub(int* nums, int l, int h){
    if(l == h) return nums[l];
    int mid = (l + h) / 2;
    int leftres = maxSub(nums, l, mid);
    int rightres = maxSub(nums, mid+1, h);
    int midres = getMidRes(nums, l, h, mid);
    return getMax(leftres, rightres, midres);
}

int maxSubArray(int* nums, int numsSize){
    return maxSub(nums, 0, numsSize-1);
}