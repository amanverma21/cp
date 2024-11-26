class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        for(auto it : edges)
        {
            vis[it[1]]=1;
        }
        int ans = -1 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(ans==-1 && vis[i]==0)
            {
                ans = i;
            }
            else if (ans != -1 && vis[i]==0)
            {
                return -1;
            }
        }
        return ans;
    }
};