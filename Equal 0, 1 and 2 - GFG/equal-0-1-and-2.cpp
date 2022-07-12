// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        // code here
        long long s = 0, z = 0, o = 0, t = 0;
        map <pair<int,int>,int> u;
        for(auto i:str){
            z += i == '0' ? 1 : 0;
            o += i == '1' ? 1 : 0;
            t += i == '2' ? 1 : 0;
            s += z == o && o == t;
            s += u[{z-o,o-t}]++  ;
        }
        return s;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}
  // } Driver Code Ends