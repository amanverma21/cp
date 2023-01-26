//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        vector<char>up,lo;
        for(int i=0;i<n;i++){
            if(str[i]>=97)
                lo.push_back(str[i]);
            else
                up.push_back(str[i]);
        }
        sort(lo.begin(),lo.end());
        sort(up.begin(),up.end());
        string ans="";
        int k=0,j=0;
        for(int i=0;i<n;i++){
            if(str[i]>=97){
                ans+=lo[j];
                j++;
            }
            else{
                ans+=up[k];
                k++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends