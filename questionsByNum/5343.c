//暴力倒退，这题数据很弱，遇到[1000000000,1]这种数据就超时
int compare(void * a, void*b){
    return *(int*)b - *(int*)a;
}

bool isPossible(int* target, int targetSize){
    qsort(target, targetSize, sizeof(int), compare);
    while(1){
        for(int i = 1; i < targetSize; ++i){
            target[0] -= target[i];
            if(target[0] <= 0)
                return false;
        }
        qsort(target, targetSize, sizeof(int), compare);
        if(target[0] == 1)
            return true;
    }
}

//实际上不需要每次都排序，因为只是要选出最大值，所以每次for循环的时候筛选出最大值即可
int compare(void * a, void*b){
    return *(int*)b - *(int*)a;
}

bool isPossible(int* target, int targetSize){
    qsort(target, targetSize, sizeof(int), compare);
    int MaxIndex = 1;
    while(1){
        for(int i = 1; i < targetSize; ++i){
            target[0] -= target[i];
            if(target[i] > target[MaxIndex])
                MaxIndex = i;
            if(target[0] <= 0)
                return false;
        }
        if(target[0] > target[MaxIndex])
            MaxIndex = 0;
        // qsort(target, targetSize, sizeof(int), compare);
        if(MaxIndex != 0){
            int temp = target[0];
            target[0]= target[MaxIndex];
            target[MaxIndex] = temp;
        }
        MaxIndex = 1;
        if(target[0] == 1)
            return true;
    }
}