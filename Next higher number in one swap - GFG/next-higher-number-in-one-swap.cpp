// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string nxtHighUsingAtMostOneSwap(string num);

int main() {
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << nxtHighUsingAtMostOneSwap(s) << endl;
    }
return 0;
}




// } Driver Code Ends


string nxtHighUsingAtMostOneSwap(string num) { 
    //complete the function here
     stack<int>s;
    int i, n=num.length(), pos=-1;
    for(i=n-1;i>=0;i--){
        while(!s.empty() && num[s.top()]>num[i]) {
            if(num[pos]!= num[s.top()])
                pos=s.top(); 
            s.pop(); 
            
        }
        if(pos<0) s.push(i);
        else break;
    }
    if(pos==-1) return "-1";
    swap(num[i], num[pos]);
    return num;
}