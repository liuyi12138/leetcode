//先找到旋转点，然后在两边二分查找
int findMid(int* nums, int  numsSize){
    int l = 0;
    int h = numsSize - 1;
    int mid;
    while(l <= h){
        mid = (l + h) / 2;
        if(nums[mid] > nums[numsSize - 1]){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    return l;
}

int findResult(int* nums, int  l, int h, int target){
    int mid;
    while(l <= h){
        mid = (l + h) / 2;
        if(target == nums[mid]) return mid;
        else if(nums[mid] < target){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    return -1;
}

int search(int* nums, int numsSize, int target){
    if(numsSize == 0) return -1;
    int mid = findMid(nums, numsSize);
    int l,h;
    if(target <= nums[numsSize-1]){
        l = mid;
        h = numsSize-1;
    }
    else{
        l = 0;
        h = mid - 1;
    }
    return findResult(nums, l, h, target);
}

