//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
    int sign = 1;
    if (s1[0] == '-') {
        sign *= -1;
        s1 = s1.substr(1);
    }
    if (s2[0] == '-') {
        sign *= -1;
        s2 = s2.substr(1);
    }
    if (s1 == "0" || s2 == "0") return "0";
    int l1 = s1.size() - 1, l2 = s2.size() - 1, carry = 0;
    string ans;
    for (int i = 0; i <= l1 + l2 || carry; i++) {
        for (int j = max(0, i - l2); j <= min(i, l1); j++)
            carry += (s1[l1 - j] - '0') * (s2[l2 - i + j] - '0');
        ans += carry % 10 + '0';
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    int start = 0;
    while (start < ans.size() && ans[start] == '0') {
        start++;
    }
    if (start == ans.size()) return "0"; 
    string result = ans.substr(start);
    if (sign == -1) {
        result = "-" + result;
    }
    return result;
}


};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends