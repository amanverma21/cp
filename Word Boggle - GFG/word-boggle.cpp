// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
 bool solve(vector<vector<char>>&board,string word,int ind,int i,int j){
        if(i<0||j<0||i==board.size()||j==board[0].size()||board[i][j]!=word[ind])return false;
        if(ind==word.size()-1)return true;

        char temp=board[i][j];
        board[i][j]='0';
        bool ok=false;
        
          ok|=solve(board,word,ind+1,i+1,j);
          ok|=solve(board,word,ind+1,i-1,j);
          ok|=solve(board,word,ind+1,i,j+1);
          ok|=solve(board,word,ind+1,i,j-1);
          ok|=solve(board,word,ind+1,i+1,j+1);
          ok|=solve(board,word,ind+1,i-1,j-1);
          ok|=solve(board,word,ind+1,i+1,j-1);
          ok|=solve(board,word,ind+1,i-1,j+1);
          
        board[i][j]=temp;
        return ok;
    }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    
	    
	  vector<string>ans;
	  
	  int n=board.size();
	  
	  int m=board[0].size();
	  
	  for(int k=0;k<dictionary.size();k++){
	      bool ok=false;
	   for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==dictionary[k][0]){
                ok=solve(board,dictionary[k],0,i,j);
                        if(ok){ans.push_back(dictionary[k]);break;}
                }
            }
            if(ok)break;
        }
	      
	  }
        return ans;}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends