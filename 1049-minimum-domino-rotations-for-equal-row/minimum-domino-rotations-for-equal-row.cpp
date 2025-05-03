class Solution {
public:
    int solve(vector<int>& t, vector<int>& b,int x){
    int up=0,down=0,c=0,maxi=0;
       for(int i=0;i<t.size();i++){
        if(t[i]==x) up++;
        if(b[i]==x) down++;
        if(t[i]==x && b[i]==x) c++;
       }
       return min(up,down)-c;
    }
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        vector<int> count(7);
        int n=t.size(),ans=INT_MAX;

        for(int i=0;i<n;i++){
          if(t[i]==b[i]){
            count[t[i]]++;
            continue;
          }
          count[b[i]]++;
          count[t[i]]++;
        }

        int maxi=*max_element(count.begin(),count.end());
        if(maxi<n) return -1;

        vector<int>total;
        for(int i=0;i<7;i++) if(count[i]==maxi) total.push_back(i);

        for(auto&x:total){
           ans=min(ans,solve(t,b,x));
        }
        return (ans>=0)?ans:0;
    }
};