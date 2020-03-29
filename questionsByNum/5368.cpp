class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mmap;
        for(int i = 0; i < arr.size(); ++i){
            mmap[arr[i]]++;
        }
        auto iter = mmap.begin();
        int res = -1;
        while(iter != mmap.end()){
            if(iter->first == iter->second && iter->first > res){
                res = iter->first;
            }
            iter++;
        }
        return res;
    }
};