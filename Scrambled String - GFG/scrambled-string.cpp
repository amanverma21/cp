//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++
unordered_map<string, int> mp;
class Solution{
    public:
    bool isScramble(string s1, string s2){
        //code here
        string key = s1 + " " + s2;
	if (mp.find(key) != mp.end())  
		return mp[key];
    if (s1.compare(s2) == 0)
		return true;
	if (s1.length() <= 1)
		return false;

	int n = s1.length();
	int flag = false;
	for (int i = 1; i <= n - 1; i++) {
		if ((isScramble(s1.substr(0, i), s2.substr(n - i, i)) && isScramble(s1.substr(i), s2.substr(0, n - i))) || 
		        (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))) {
			flag = true; 
			break;
		}
	}

	return mp[key] = flag;
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends