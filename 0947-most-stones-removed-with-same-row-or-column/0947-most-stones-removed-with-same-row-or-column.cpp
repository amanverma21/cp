class Solution {
public:
    int dfs(vector<vector<int>> &stones, vector<int> &visited, int i, int s, int r){
	        visited[i] = 1;
	        for(int j = 0; j < s; j++){
		        if( (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) && visited[j] == 0 ){
			        r = dfs(stones, visited, j, s, r);       
		        }                                                   
	        }
	        r = r + 1;
	        return r;
        }

        int removeStones(vector<vector<int>>& stones) {
	        int s = stones.size();
	        vector<int> visited(s, 0);  
	        int ans = 0;
	        for(int i = 0; i<s; i++){     
		        if(visited[i] == 0) {                        
			        ans = dfs(stones, visited, i, s, ans);   
			        ans--;                                             
		        }    
	        }
	        return ans;
    }
};