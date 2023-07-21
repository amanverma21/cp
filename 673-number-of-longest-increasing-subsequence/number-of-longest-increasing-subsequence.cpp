class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n=a.size();
        
        vector<int> dp(n,1), count(n,1);
        int max_len=0;
		
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(a[i]>a[j]){
                    if(dp[i]<1+dp[j]){ 
                        count[i]=count[j]; 
                    }else if(dp[i]==1+dp[j]){
                        count[i]+=count[j]; 
                    }
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            max_len=max(max_len,dp[i]);
        }
        
        int c=0;
        for(int i=0;i<n;i++){
            if(dp[i]==max_len) c += count[i];
        }
        
        return c;
    }
};