class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int n=mat.size();
        int m=mat[0].size();
        vector<pair<int,int>>rows;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                cnt+=mat[i][j];
            }
            rows.push_back({cnt, i});
        }
        sort(rows.begin(),rows.end());
        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(rows[i].second);
        }
        return res;
    }
};
