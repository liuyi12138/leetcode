class Solution {
    int ne[100005];
    string ans;
public
    string longestPrefix(string s) {
        int n=s.size(),i,j;
        for(ne[1]=j=0,i=2;i=n;i++)
        {
            while(j&&s[j]!=s[i-1])j=ne[j];
            if(s[j]==s[i-1])j++;
            ne[i]=j;
        }
        ans.clear();
        for(i=0;ine[n];i++)ans+=s[i];
        return ans;
    }
};