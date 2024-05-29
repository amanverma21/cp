class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        int cnt=0;
        while(s.size()>1){
           if(s[s.size()-1]=='1'){
            bool flag=false;
            for(int i=s.size()-1;i>=0;i--){
                  if(s[i]=='0'){
                    s[i]='1';
                    flag=true;
                    break;
                  }
                  else{
                    s[i]='0';
                  }
            }
            if(flag==false){
                s='1'+s;
            }
            cnt++;
           }
           else{
            s.pop_back();
            cnt++;
           }
        }
        return cnt;
    }
};