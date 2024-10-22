class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        unordered_map<int, long long> levelSum; 
        int levels = 0;
        queue<pair<TreeNode*, int>> q; 
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();
            if (!node) continue;
            levelSum[level] += node->val;
            levels = max(levels, level);
            q.push({node->left, level + 1});
            q.push({node->right, level + 1});
        }
        int ans = 1,dir=1,cnt=0,n=1,time=1; 
    for (int i = 1; i <= time; i++) {
        if (ans == 1) {
            dir = 1; 
            cnt++;
        } else if (ans == n) {
            dir = -1; 
        }
        ans += dir;
    }
        vector<long long> sums;
        for (int i = 0; i <= levels; ++i) {
            sums.push_back(levelSum[i]);
        }
        sort(sums.rbegin(), sums.rend());
        if(sums.size()<k)
            return -1;
        return sums[k - 1];
    
    }
};
