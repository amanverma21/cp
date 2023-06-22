//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
         if(bills[0]!=5)
        return 0;
        map<int,int> m;
        for(int i=0;i<N;i++)
        {
            m[bills[i]]++;
            if(bills[i]==10)
            {
                if(m[5]!=0)
                m[5]--;
                else
                return 0;
            }
            else if(bills[i]==20)
            {
                if(m[10]>=1 && m[5]>=1)
                {m[10]--;m[5]--;}
                else if(m[5]>=3)
                {m[5]--;m[5]--;m[5]--;}
                else
                return 0;
            }
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends