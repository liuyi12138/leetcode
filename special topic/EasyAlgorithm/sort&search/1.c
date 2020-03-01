//暴力解法，qsort直接排序
int compare(void* a, void*b){
    return *(int*)a - *(int*)b;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i = 0; i < n; ++i){
        nums1[m+i] = nums2[i];
    }
    qsort(nums1, m+n, sizeof(int), compare);
}

//由于合并后的数组具有特定规律(前后排序完成)，可采用特定方法进行排序(原地归并排序)
void reverse(int* nums,int start, int end)
{
    int i = start;
    int j = end - 1;
    int temp;
    while (i<j)
    {
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
}

void exchange(int* nums,int start, int mid, int end)
{
    reverse(nums, start, mid);
    reverse(nums, mid, end);
    reverse(nums, start, end);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i = 0; i < n; ++i){
        nums1[m+i] = nums2[i];
    }

    int i = 0;
    int j = m;
    int mid = m;
    while (i < j && j < m+n)
    {
        int step=0;
        while (i < j && nums1[i] <= nums1[j])
            i++;
        while (j < m+n && nums1[j] < nums1[i])
        {
            j++;
            step++;
        }
        exchange(nums1,i,mid,j);
        i += step;
        mid = j;
    }
}



/*
    既然要用归并排序的合并思想要用新的空间，那不如直接用num2的空间
    采用双指针比较法来合并
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = 0;
    int j = 0;
    int count = 1;
    while(i < m && j < n){
        if(nums1[m-1-i] > nums2[n-1-j]){
            nums1[m+n-count] = nums1[m-1-i];
            i++;
        }
        else{
            nums1[m+n-count] = nums2[n-1-j];
            j++;
        }
        count++;
    }
    while(j < n){
        nums1[m+n-count] = nums2[n-1-j];
        j++;
        count++;
    }
}
