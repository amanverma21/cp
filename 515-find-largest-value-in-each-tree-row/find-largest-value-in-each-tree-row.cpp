/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<vector<int>>&ans, int level=0){
        if(!root) return;
        if(level>=ans.size()) ans.push_back({});
        ans[level].push_back(root->val);
        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root,ans);
        vector<int>res;
        for(auto it:ans){
            int mx = *max_element(it.begin(),it.end());
            res.push_back(mx);
        }
        return res;
    }
};