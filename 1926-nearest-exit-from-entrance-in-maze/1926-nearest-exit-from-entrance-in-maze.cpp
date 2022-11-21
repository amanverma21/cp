class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n = maze.size();
        int m = maze[0].size();
        int er = entrance[0];
        int ec = entrance[1];
        
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        vector<int> drow {0, -1, 0, 1};
        vector<int> dcol {-1, 0, 1, 0};
        
        queue<pair<int,pair<int,int>>> q;

        q.push({0,{er,ec}});
        vis[er][ec] = false;
         
        while(!q.empty())   {
            auto it = q.front();
            q.pop();
            int steps = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i=0; i<4; i++)  {
                int dr = r+drow[i];
                int dc = c+dcol[i];
                
                if(dr>=0&&dr<n&&dc>=0&&dc<m&&vis[dr][dc]==false&&maze[dr][dc]=='.') {
                    if(dr==n-1 || dr==0 || dc==m-1 || dc==0 ) {       
                        if(dr!=er || dc!=ec )       
                            return steps+1;
                    }
                    
                    q.push({steps+1, {dr,dc}});
                    vis[dr][dc]=true;
                }
            }
        }
        
        return -1;
    }
};