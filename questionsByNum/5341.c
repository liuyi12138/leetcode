//暴力解法
typedef struct {
    int len;
    int data[40000];
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* obj = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
    obj->len = 0;
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    (obj->data)[obj->len] = num;
    obj->len += 1;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    // printf("%d %d\n",k,obj->len);
    if(k <= obj->len){
        int result = 1;
        for(int i = obj->len - k; i < obj->len; ++i){
            result *= (obj->data)[i];
            if(result == 0) return 0; 
        }
        // printf("%d",result);
        return result;
    }
    return 0;
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/


//维护前缀积 存在0的问题有点难解决
typedef struct {
    int len;
    int zeroIndex;
    long int data[40000];
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* obj = (ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
    obj->len = 0;
    obj->zeroIndex = -1;
    return obj;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    if(num == 0){
        obj->zeroIndex = obj->len;
        (obj->data)[obj->len] = 1;
    }
    else if(obj->len == 0)
        (obj->data)[obj->len] = num;
    else
        (obj->data)[obj->len] = (obj->data)[(obj->len)-1] * num;
    obj->len += 1;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    if(obj->len-k <= obj->zeroIndex)
        return 0;
    if(k == obj->len)
        return (obj->data)[obj->len-1];
    if(k < obj->len){
        return ((obj->data)[obj->len-1] / (obj->data)[obj->len-1-k]);
    }
    return 0;
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);
 
 * int param_2 = productOfNumbersGetProduct(obj, k);
 
 * productOfNumbersFree(obj);
*/