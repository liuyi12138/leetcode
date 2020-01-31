//最直观的遍历方式 时间复杂度O(n^2) 空间复杂度O(1)
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* result = (int*)malloc(2*sizeof(int));
    for(int i = 0; i < numsSize; ++i){
        for(int j = i + 1; j < numsSize; ++j){
            if(nums[i] + nums[j] == target){
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return result;
}

/*
    分治法实现2Sum，思路为把数组分为两半，问题变为3个子问题：
    2个数都在左侧/2个数都在右侧/左右各一个
    如果两个数在同侧则继续递归，最小子问题为只剩两个数时直接比较，只剩一个数时判false
    如果两个数分别在两边，则for循环遍历两侧，时间复杂度为O(n^2),但系数为原来的1/4
    此方法时间复杂度为O(n^2),最理想条件下时间复杂度为O(nlogn),空间复杂度为O(1)
*/
int ergodic(int* nums, int l, int h, int target, int* result){
    int med = (l + h) / 2;
    for(int i = l; i <= med; ++i){
        for(int j = med + 1; j <= h; ++j){
            if(target == nums[i] + nums[j]){
                result[0] = i;
                result[1] = j;
                return 1;
            }
        }
    }
    return 0;
}

int find2Sum(int* nums, int l, int h, int target, int* result){
    if(h <= l)
        return 0;
    if(h == l + 1){
        if(target == nums[l] + nums[h]){
            result[0] = l;
            result[1] = h;
            return 1;
        }
        return 0;
    }
    int med = (l + h) / 2;
    int leftRes = find2Sum(nums, l, med, target, result);
    int rightRes = find2Sum(nums, med, h, target, result);
    if(!leftRes && !rightRes)
        return ergodic(nums, l, h, target, result);
    else
        return 1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 0;
    if(numsSize <= 1) return NULL;
    int* result = (int*)malloc(2*sizeof(int));
    if(find2Sum(nums, 0, numsSize-1, target, result)){
        *returnSize = 2;
    }
    else{
        *returnSize = 0;
    }
    return result;
}

/*
    思路为排序后查询，需要开辟空间来存储原数组防止丢失索引
    查询采用一个for循环+二分查找
    排序和查询的时间复杂度都为O(nlogn),算法的空间复杂度为O(n)
    (这个二分查找代码的边界条件有问题aaaaa，真的调不出来，代码思路在这，凑合着看)
*/
int compare(void* a, void* b){
    return *(int*)a - *(int*)b;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* temp = (int*)malloc(numsSize*sizeof(int));
    int* result = (int*)malloc(2*sizeof(int));
    int resultl, resulth;
    for(int i = 0; i < numsSize; ++i){
        temp[i] = nums[i];
    }
    qsort(temp, numsSize, sizeof(int), compare);
    int flag = 0;
    for(int i = 0; i < numsSize; ++i){
        if(flag) break;
        int l = i;
        int h = numsSize - 1;
        while(l <= h){
            int mid = (l + h) / 2;
            if(temp[i] + temp[mid] == target){
                resultl = temp[i];
                resulth = temp[mid];
                flag = 1;
                break;
            }
            else if(temp[l] + temp[mid] > target) h = mid - 1;
            else l = mid + 1;
        }
    }
    if(flag){
        *returnSize = 2;
        int flagl = 0;
        int flagh = 0;
        for(int i = 0; i < numsSize; ++i){
            if(!flagl && nums[i] == resultl){
                result[0] = i;
                flagl = 1;
            }
            else if(!flagh && nums[i] == resulth){
                result[1] = i;
                flagh = 1;
            }
        }
    }
    else{
        *returnSize = 0;
    }
    return result;
}

/*
    上一个思路的改进，改进点为查询
    因为qsort的时间复杂度最差为O(nlogn)，但查询一定是O(nlogn)所以需要改进
    将二分法改为双指针遍历的方法，时间复杂度为O(n)
    算法整体的时间复杂度还是O(nlogn),空间复杂度为O(n)

*/
int compare(void* a, void* b){
    return *(int*)a - *(int*)b;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* temp = (int*)malloc(numsSize*sizeof(int));
    int* result = (int*)malloc(2*sizeof(int));
    int resultl, resulth;
    for(int i = 0; i < numsSize; ++i){
        temp[i] = nums[i];
    }
    qsort(temp, numsSize, sizeof(int), compare);
    int flag = 0;
    int l = 0;
    int h = numsSize - 1;
    while(l < h){
        if(temp[l] + temp[h] == target){
            resultl = temp[l];
            resulth = temp[h];
            flag = 1;
            break;
        }
        else if(temp[l] + temp[h] < target) l++;
        else h--;
    }

    if(flag){
        *returnSize = 2;
        int flagl = 0;
        int flagh = 0;
        for(int i = 0; i < numsSize; ++i){
            if(!flagl && nums[i] == resultl){
                result[0] = i;
                flagl = 1;
            }
            else if(!flagh && nums[i] == resulth){
                result[1] = i;
                flagh = 1;
            }
        }
    }
    else{
        *returnSize = 0;
    }
    return result;
}