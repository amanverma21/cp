class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st(banned.begin(), banned.end());
        long long sum = 0;
        int count = 0;    
        for (int i = 1; i <= n; i++) {
            if (st.count(i)) continue; 
            sum += i; 
            if (sum > maxSum) break; 
            count++; 
        }
        return count; 
    }
};