int hammingWeight(uint32_t n) {
    int count = 0;
    while(n > 0){
        if(n % 2 == 1)
            count++;
        n = n / 2;
    }
    return count;
}

int hammingDistance(int x, int y){
    uint32_t n = x ^ y;
    return hammingWeight(n);
}

