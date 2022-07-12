// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
unsigned long long int findpos(string n);
int main()
{  
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string a;
        cin>>a;
        cout << findpos(a)<<endl;
    }
    return 0;
}// } Driver Code Ends


unsigned long long int findpos(string n)
{
     unsigned long long int sum=0,p=1;
   for(int i=n.size()-1;i>=0;i--){
       if(n[i]=='7') sum+=p;
       p=p*2;
   }
   return sum+pow(2,n.size())-1;
}