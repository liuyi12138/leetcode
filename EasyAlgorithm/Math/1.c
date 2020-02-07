

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    *returnSize = n;
    char** result = (char**)malloc(n*sizeof(char*));
    for(int i = 1; i < n+1; ++i){
        result[i-1] = (char*)malloc(8*sizeof(char));
        if(i % 3 == 0){
            if(i % 5 == 0)
                result[i-1] = "FizzBuzz";
            else
                result[i-1] = "Fizz";
            continue;
        }
        else if(i % 5 == 0)
            result[i-1] = "Buzz";
        else{
            sprintf(result[i-1], "%d", i);
        }
    }
    return result;
}

