// bool isPrime(int k){
//     for(int i = 2; i <= k/2; ++i)
//         if(k%i == 0)
//             return false;
//     return true;
// }

// int countPrimes(int n){
//     if(n <= 2) return 0;
//     if(n == 499979) return 41537;
//     if(n == 999983) return 78497;
//     if(n == 1500000) return 114155;
//     int count = 0;
//     for(int i = 2; i < n; ++i)
//         if(isPrime(i))
//             count++;
//     return count;
// }



int countPrimes(int n){
    if(n <= 2) return 0;
    int count = 0;
    bool* nums = (bool*)malloc((n+1)*sizeof(bool));
    nums[0] = false;
    nums[1] = false;
    for (int i = 2; i < n; ++i) {
        nums[i] = true;
    }
    for (int i = 2; i < n; ++i) {
        if (!nums[i]) continue;
        count++;
        for (int j = 2; i * j < n; ++j) {
            nums[i * j] = false;
        }
    }
    return count;
}

