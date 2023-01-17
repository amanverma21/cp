class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.length();
        int cntone=0,cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1')
                cntone++;
            else
                cnt++;
            cnt=min(cnt,cntone);
        }
        return cnt;
        
    }
};