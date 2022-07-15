// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
 

class Solution{
    public:
    
    // X[], Y[]: input arrau
    // M, N: size of arrays X[] and Y[] respectively
    //Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(int X[], int Y[], int m, int n)
    {
       //Your code here
       long long count_one = count(X,X+m,1);
       long long s = (m-count_one)*count(Y,Y+n,1);
       
       //if y=2,4 : x=3
       s+=count(Y,Y+n,2)*count(X,X+m,3);
       s+=count(Y,Y+n,4)*count(X,X+m,3);
       
       //y>4 :  1<x<y
       sort(X,X+m);
       
       for(int i=0;i<n;i++)
       {
           if(Y[i]==1 or Y[i]==2 or Y[i]==3 or Y[i]==4) 		continue;
            s+= (lower_bound(X,X+m,Y[i]) - X) - count_one;
       }
       
       return s;
    }
};


// { Driver Code Starts.
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int M,N;
		cin>>M>>N;
		int i,a[M],b[N];
		for(i=0;i<M;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<N;i++)
		{
			cin>>b[i];
		}
		Solution ob;
		cout<<ob.countPairs(a, b, M, N)<<endl;
	}
}  // } Driver Code Ends