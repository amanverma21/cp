//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        // Write Your Code here
        // vector<int> v(N+1,0);
        // for(int i=1;i<=N;i++){
        //     for(int j=i;j<=N;j+=i){
        //         v[j]+=i;
        //     }
        // }
        // int res=0;
        // for(int i=1;i<=N;i++){
        //     res+=v[i];
        // }
        // return res;
        long long res=0;
        for(int i=1;i<=N;i++){
            res+=(N/i)*i;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends