//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    #define ll unsigned long long
    //power of 5 
    bool ispower(ll n)
    {
    if (n < 125)
        return (n == 1 || n == 5 || n == 25);
    if (n % 125 != 0)
        return false;
    else
        return ispower(n / 125);
    }
    
    //for binary to decimal
    ll number(string s, int i, int j)
    {
    ll ans = 0;
    for (int x = i; x < j; x++) {
        ans = ans * 2 + (s[x] - '0');
    }
    return ans;
    }
    int cuts(string s){
        //code
        int n=s.length();
        //  return __builtin_popcount(s)==4;
         int dp[n + 1];
    memset(dp, n + 1, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0')
            continue;
        for (int j = 0; j < i; j++) {
            if (s[j] == '0')
                continue;
            ll num = number(s, j, i);
            // Check for power of 5
            if (!ispower(num))
                continue;
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    return ((dp[n] < n + 1) ? dp[n] : -1);

    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends