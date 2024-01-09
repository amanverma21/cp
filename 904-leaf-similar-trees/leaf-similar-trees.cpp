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

    void solve(TreeNode* root, vector<int>& leafNodes) {
        if (root) {
            if (!root->left && !root->right) {
                leafNodes.push_back(root->val);
            }
            solve(root->left, leafNodes);
            solve(root->right, leafNodes);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        solve(root1,v1);
        solve(root2,v2);
        return (v1==v2);
    }
};