class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        int n = nums.size(), m = queries.size();
        priority_queue<int> pq;
        vector<int> reduction(n + 1, 0);
        int k = 0, usedCnt = 0;
        for(int i = 0; i < n; i++) {
            if(i > 0)   reduction[i] += reduction[i - 1];
            while(k < m && queries[k][0] <= i)
                pq.push(queries[k++][1]);
            while(nums[i] > reduction[i]) {
                if(pq.empty() || pq.top() < i)
                    return -1;
                usedCnt++;
                int top = pq.top();
                pq.pop();
                reduction[i]++;
                reduction[top + 1]--;
            }
        }
        return m - usedCnt;
    }
};