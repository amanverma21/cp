//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    //code here.
      int i=0,n=num.length();
    int x=k;
    while(k--){
        while(num.length()!=(n-(x-k))){
            if(i!=0 && num[i]<num[i-1])
             i--;
            else if(i!=num.length()-1 && num[i]<num[i+1])
             i++;
            else{
              if(num[i]==num[i+1] && i<num.length()-1)
                i++;
              else    
                num.erase(i,1);
            }
            if(i==num.length())
             i--;
        }
    }
    i=0;
    while(i!=num.length()-1 && num[i]=='0')
     num.erase(i,1);
  return num;      
}