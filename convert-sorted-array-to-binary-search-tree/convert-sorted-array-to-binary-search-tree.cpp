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
    TreeNode* solve(int left,int right,vector<int>&ans){
        if(left>right) return NULL;
        int mid=(left+right)/2;

        TreeNode* root=new TreeNode(ans[mid]);
        root->left=solve(left,mid-1,ans);
        root->right=solve(mid+1,right,ans);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return solve(0,nums.size()-1,nums);
        

    }
};