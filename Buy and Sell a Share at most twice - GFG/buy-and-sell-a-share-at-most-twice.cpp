//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    vector<int> pft(n,0);
    int ans=price[n-1];
    for(int i=n-2;i>=0;i--){
        if(price[i]>ans) ans=price[i];
        pft[i]=max(pft[i+1],ans-price[i]);
    }
    int res=price[0];
    for(int i=1;i<n;i++){
        if(price[i]<res) 
            res=price[i];
        pft[i]=max(pft[i-1],pft[i]+(price[i]-res));
    }
    return pft[n-1];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends