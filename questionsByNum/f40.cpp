class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        vector<int> result;
        int n =arr.size();
        if(n==0) return result;

        int l =0, r=n-1;
        fast_order(arr,l,r,k);

        for(int i=0; i<k; i++)
            result.push_back(arr[i]);
        
        return result;

    }

    void fast_order(vector<int>& arr, int star, int end, int target)
    {
        if(star>end) return;
        int p =arr[star];
        int l =star; int r=end;
        while(l<r)
        {
            while(l<r && arr[r]>p)
                r--;
            
            if(l<r) arr[l++] = arr[r];

            while(l<r && arr[l]<p)
                l++;
            
            if(l<r) arr[r--] =arr[l];
        }

        arr[l] =p;
        if(l==target)
            return;
        if(l<target)
            fast_order(arr,l+1,end,target);
        else
            fast_order(arr,star,l-1,target);

    }
};