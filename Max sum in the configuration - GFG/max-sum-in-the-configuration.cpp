//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int n)
{
//Your code here
int sum =0,prev=0;
for(int i=0; i<n;i++){
    sum+=A[i];
    prev+=(A[i]*i);
}
int mx = prev;
for(int i=0; i<n;i++){
    prev = (prev-(sum-A[i]))+(A[i]*(n-1));
    mx = max(mx,prev);
}
return mx;
}