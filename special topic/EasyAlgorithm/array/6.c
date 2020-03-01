/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void*a,const void*b)
{
    //坑点在于a-b可能会造成溢出
    if(*(int*)a > *(int*)b)
        return 1;
    else
        return -1;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int i = 0;
    int j = 0;
    int count = 0;
    int numsize = nums1Size > nums2Size ? nums2Size : nums1Size;
    int* nums3 = malloc(numsize*sizeof(int));
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);
    
    while(i < nums1Size && j < nums2Size){
        if(nums1[i] == nums2[j]){
            nums3[count] = nums1[i];
            ++i;
            ++j;
            ++count;
        }
        else if(nums1[i] > nums2[j]){
            ++j;
        }
        else{
            ++i;
        }
    }
    *returnSize = count;
    return nums3;
}

