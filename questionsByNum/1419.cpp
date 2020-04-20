//暴力法超时
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        if(croakOfFrogs.size() % 5 != 0)
            return -1;
        if(croakOfFrogs[0] != 'c')
            return -1;
        vector<bool> used(croakOfFrogs.size(), false);
        string croak = "croak";
        int cIndex = 0;
        int index = 1;
        int minFrog = 1;
        int nowFrog = 1;
        for(int i = 1; i < croakOfFrogs.size();){
            while(used[i])
                ++i;
            if(croakOfFrogs[i] == croak[index]){
                used[i] = true;
                ++i; ++index;
                if(index == 5){
                    index = 0;
                    if(cIndex != i - 5 && cIndex != 0){
                        i = cIndex;
                        cIndex = 0;
                    } 
                    nowFrog = 1;
                }
            }
            else if(croakOfFrogs[i] == 'c' && index != 0){
                if(cIndex == 0)
                    cIndex = i;
                nowFrog += 1;
                minFrog = max(minFrog, nowFrog);
                ++i;
            }
            else
                ++i;
        }
        minFrog = max(minFrog, nowFrog);
        if(index == 0)
            return minFrog;
        return -1;
    }
};

//yx题解
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c=0;
        int r=0;
        int o=0;
        int a=0;
        int k=0;
        int re=0;
        bool flag=true;
        for(int i=0; i<croakOfFrogs.size(); i++){
            if (croakOfFrogs[i]=='c') c++;
            if (croakOfFrogs[i]=='r') r++;
            if (croakOfFrogs[i]=='o') o++;
            if (croakOfFrogs[i]=='a') a++;
            re=max(re, c);//遇到k前要判断有多少个c同时存在
            if (croakOfFrogs[i]=='k'){//遇到k就要规约一个croak
                k++;
                if (c>=r && r>=o && o>=a && a>=k){
                c--;
                r--;
                o--;
                a--;
                k--;
                }
                
            }
            if(!(c>=r && r>=o && o>=a && a>=k)){//必须保持任意时刻（c>=r>=o>=a>=k）,才是正确的；否则就是错误的，
                flag=false;
                break;
            }
            
        }
        if (c!=0 || r!=0 || o!=0 || a!=0 ||k!=0) flag=false;//如果最后有剩的字母，也是错误的
        if (flag==true) return re;
        else return -1;
    }
};
