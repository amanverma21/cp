class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
        int n = grid.size();
        int m = grid[0].size();
        int nrow[] = {0, 0, 1, -1};
        int ncol[] = {1, -1, 0, 0};

        vector<vector<int>>path(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        
        pq.push({0, {0, 0}});
        path[0][0] = 0;

        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            int cost = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;

            if(row == n-1 && col == m-1) return cost;

            for(int i = 0;i < 4;i++){
                int newrow = row + nrow[i];
                int newcol = col + ncol[i];

                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m){
                    if(i == (grid[row][col] - 1) && path[newrow][newcol] > cost){
                        path[newrow][newcol] = cost;
                        pq.push({cost, {newrow, newcol}});
                    }
                    else if(path[newrow][newcol] > cost + 1){
                        path[newrow][newcol] = cost + 1;
                        pq.push({cost + 1, {newrow, newcol}});
                    }
                }
            }
        }
        return -1;
    }
};