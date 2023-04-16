//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  #define ll long long
    long long solve(int n, vector<int> &A, vector<int> &B) {
        // code here
        vector<ll>evA,odA,evB,odB;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        for(int i=0;i<n;++i){
            if(A[i]%2)
                odA.push_back(A[i]);
            else
                evA.push_back(A[i]);
        }
        for(int i=0;i<n;++i){
            if(B[i]%2)
                odB.push_back(B[i]);
            else
                evB.push_back(B[i]);
        }
        if(evA.size()!=evB.size())
            return -1;
        ll inc=0,dec=0;
        bool ok = true;
        
        for(int i=0;i<evA.size();++i){
           
            ll dif=abs(evB[i]-evA[i]);
      
            if(dif%2){
                ok=false;
                break; 
            }
            if(evA[i]>=evB[i]){
                dec+=dif;
            }else{
                inc+=dif;
            }
        }
        for(int i=0;i<odA.size();++i){
            
            ll dif=abs(odB[i]-odA[i]);
           
            if(dif%2){
                ok=false;
                break; 
            }
            if(odA[i]>=odB[i]){
                dec+=dif;
            }else{
                inc+=dif;
            }
        }
        
        if(inc==dec and ok)
            return inc/2;
        return -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends