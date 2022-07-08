// { Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> constructLowerArray(int *arr, int n) {
	    // code here
	     vector<int> countSmaller(n, 0);
    tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
        ordered_set;
    for (int i = n - 1; i >= 0; i--) {
        countSmaller[i] = ordered_set.order_of_key(arr[i]);
        ordered_set.insert(arr[i]);
    }
    return countSmaller;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends