//Memoisation
class Solution {
public:
    vector<vector<int>> dp;
    int fun(int idx1,int idx2,int n,int m,vector<int>& nums1,vector<int>& nums2){
        if(idx1==n or idx2==m) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        if(nums1[idx1]==nums2[idx2]){
            return dp[idx1][idx2]=1+fun(idx1+1,idx2+1,n,m,nums1,nums2);
        }
        else{
            return dp[idx1][idx2]=max(fun(idx1+1,idx2,n,m,nums1,nums2),fun(idx1,idx2+1,n,m,nums1,nums2));
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        dp=vector<vector<int>>(n,vector<int>(m,-1));
        return fun(0,0,n,m,nums1,nums2);
    }
};