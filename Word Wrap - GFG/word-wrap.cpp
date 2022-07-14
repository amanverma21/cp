// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int help(vector<int>& nums, int i, int left, int k, vector<vector<int>>& memo){
        if(i==nums.size()){
            return 0;
        }
        if(memo[i][left]!=-1) return 		memo[i][left];
        int cost=pow(left,2);
        if(left<=nums[i]) return memo[i][left]=cost+help(nums,i+1,k-nums[i],k,memo);
        return memo[i][left]=min(cost+help(nums,i+1,k-nums[i],k,memo),help(nums,i+1,left-nums[i]-1,k,memo));
    }
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        vector<vector<int>> memo(nums.size(),vector<int>(k+1,-1));
        return help(nums,1,k-nums[0],k,memo);
    }  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends