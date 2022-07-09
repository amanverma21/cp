// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    long long int countDivisorsMult(int arr[], int n)
    {
         int k = *max_element(arr,arr+n);
        vector<int>isprime(k+1,1);
        vector<int>lp(k+1,0);
        isprime[0]=isprime[1]=0;
        
        // Using Sieve to store prime numbers
        for(int i=2;i<=k;i++)
        {
            if(isprime[i]==1)
            {
                lp[i] = i;
                for(int j=i*2;j<=k;j+=i)
                {
                    isprime[j] = 0;
                    if(lp[j]==0)
                    lp[j] = i;
                }
            }
        }
        
        // Storing frequency of prime_factors in a map
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            int prime_factor=lp[arr[i]];
            int temp = arr[i];
            while(temp>1)
            {
                while(temp%prime_factor==0)
                {
                    temp=temp/prime_factor;
                    m[prime_factor]++;
                }
                prime_factor = lp[temp];
            }
        }
        long res=1;
        for(auto x:m)
        {
          // let we have prime_factor 3 with 2 frequency so to
          // find factor (num*3), (num*9) and (num) thats why i added 
          // 1 to x.second
           res *= (x.second+1);    
        }
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
	  int n,i;
	  cin>>n; int arr[n];
	  for(i=0;i<n;i++)
	  cin>>arr[i];
	  Solution obj;
	  cout <<obj.countDivisorsMult(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends