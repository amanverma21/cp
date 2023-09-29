class Solution {
public:
    int solve(vector<int> &v1,vector<int> &v2,int i,int j,int &m,int &n,vector<vector<int>> &v){
        if(i==n||j==m){
            return 0;
        }
        if(v[i][j]!=-1)return v[i][j];
        if(v1[i]==v2[j]){
            v[i][j] = 1+solve(v1,v2,i+1,j+1,m,n,v);
        }else{
            v[i][j] = max({solve(v1,v2,i+1,j,m,n,v),solve(v1,v2,i,j+1,m,n,v),v[i][j]});
        }
        return v[i][j];
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m=nums2.size();;
        vector<vector<int>> v(n+1,vector<int>(m+1,-1));
        return solve(nums1,nums2,0,0,m,n,v);
    }
};