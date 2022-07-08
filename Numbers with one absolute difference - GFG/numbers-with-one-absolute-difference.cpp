// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    vector<long long> res;
    void rec(long long &N, long long curr){
        if(curr > N) return;
        if((int)log10(curr) != 0) res.push_back(curr);
        
        int m = curr % 10;
        if(m != 9) rec(N, curr * 10 + (m + 1));
        if(m != 0) rec(N, curr * 10 + (m - 1));
    }
    vector<long long> absDifOne(long long N)
    {
        //code here.
        for(int i = 1; i <= 9; i++){
            rec(N, i);
        }
        sort(res.begin(), res.end());
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
        {
            long long n;
            cin>>n;
            Solution ob;
            vector<long long> res = ob.absDifOne(n);
            for(int i = 0;i<res.size();i++)
                cout<<res[i]<<" ";
            if(res.size()==0)
                cout<<-1;
            cout<<endl;    
        }
}
  // } Driver Code Ends