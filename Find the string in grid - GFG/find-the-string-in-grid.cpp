// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isOutOfBounds(int x,int y,int n,int m){
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	       vector<vector<int>> ans;
        int n = grid.size(), m = grid[0].size();
        int x[] = {1, -1, 0, 0, 1, -1, -1, 1};
        int y[] = {0, 0, 1, -1, -1, -1, 1, 1};

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == word[0])
                {
                    bool flag = false;
                    for (int d = 0; d < 8 && !flag; d++)
                    {
                        int k = 1, dx = i, dy = j;
                        for (k; k < word.length(); k++)
                        {
                            dx += x[d], dy += y[d];
                            if (!(isOutOfBounds(dx,dy,n,m) && grid[dx][dy] == word[k]))
                                break;
                        }
                        if (k == word.length())
                            ans.push_back({i, j}), flag = true;
                    }
                }
        return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends