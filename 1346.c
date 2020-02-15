int compare(void* a, void* b){
    return *(int*)a - *(int*)b;
}

bool checkIfExist(int* arr, int arrSize){
    qsort(arr, arrSize, sizeof(int), compare);
    int zeroIndex = arrSize-1;
    for(int i = 0; i < arrSize-1;++i)
        if(arr[i] >= 0){
            zeroIndex = i;
            break;
        }
    for(int i = zeroIndex; i < arrSize-1; ++i){
        if(2 * arr[i] > arr[arrSize-1]) break;
        int l = i;
        int h = arrSize - 1;
        int mid;
        while(l <= h){
            mid = (l + h) / 2;
            // printf("%d: %d %d %d\n",i,l,h,mid);
            if(2 * arr[i] == arr[mid] && mid != i) 
                return true;
            else if(2 * arr[i] < arr[mid])
                h = mid - 1;
            else
                l= mid + 1;
        }
    }
    for(int i = zeroIndex-1; i > 0; --i){
        if(2 * arr[i] < arr[0]) return false;
        int l = i;
        int h = 0;
        int mid;
        while(l >= h){
            mid = (l + h) / 2;
            // printf("%d: %d %d %d\n",i,l,h,mid);
            if(2 * arr[i] == arr[mid]) 
                return true;
            else if(2 * arr[i] < arr[mid])
                l= mid - 1;
            else
                h = mid + 1;
        }
    }
    return false;
}

