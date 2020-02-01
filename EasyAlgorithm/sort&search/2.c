// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    if(n == 0 || n == 1) return n;
    int l = 1;
    int h = n;
    int mid;
    int result;
    while(l <= h){
        mid = l + (h - l) / 2;
        if(!isBadVersion(mid)){
            l = mid + 1;
        }
        else{
            result = mid;
            h = mid - 1;
        }
    }
    return result;
}