class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int>st;
        int ans=0,cnt=0;
        for(int i=1;i<100000;i++){
            if(st.find(i)==st.end()){
                ans+=i;
                cnt++;
                if(cnt==n) break;
                if(k-i>0) st.insert(k-i);
            }
        }
        return ans;
    }
};