#define all(v) v.begin(), v.end()
class Solution {
public:
    typedef long long ll;
    long long totalCost(vector<int>& costs, int k, int can) {
        int n = costs.size();
        if(n <= 2 * can) {
            ll ans = 0;
            sort(all(costs));
            for(int i = 0; i < k; i++)
                ans += costs[i];
            return ans;
        }
        priority_queue<int, vector<int>, greater<int>> q1, q2;
        int i, j;
        for(i = 0; i < can; i++) q1.push(costs[i]);
        for(j = n - 1; j >= n - can; j--) q2.push(costs[j]);
        ll ans = 0;
        while(k--) {
            if((!q1.empty() && !q2.empty() && q1.top() <= q2.top()) || q2.empty()) {
                ans += q1.top(); q1.pop();
                if(i <= j) q1.push(costs[i++]);
            } else {
                ans += q2.top(); q2.pop();
                if(i <= j) q2.push(costs[j--]);
            }
        }
        return ans;
    }
};