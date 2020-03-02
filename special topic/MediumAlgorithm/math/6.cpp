//大数处理比较麻烦，不如直接long
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==0) return 0;
        int sign=((dividend<0)^(divisor<0))? -1 : 1;
        long x=(dividend<0)? -(long)dividend : (long)dividend;
        long y=(divisor<0)? -(long)divisor : (long)divisor;
        long result=0;
        while(x>=y)
        {
            long temp=y,mid=1;
            while(x>=(temp<<1))
            {
                mid<<=1;
                temp<<=1;
            }
            result+=mid;
            x-=temp;
        }
        return sign>0 ? result : -result;
    }
};
