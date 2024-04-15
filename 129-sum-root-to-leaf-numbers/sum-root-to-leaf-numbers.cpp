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

    void helper(TreeNode* node, int& sum , int& ans){
        if(node == NULL){
            
            return;
        }

        sum *= 10;
        sum += node -> val;
        helper(node -> left , sum , ans);
        
        helper(node -> right , sum , ans);

        if(node -> left == NULL && node -> right == NULL){
            ans += sum;
        }

        sum -= node -> val;
        sum /= 10;
        return;
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int sum = 0;

        if(root == NULL) return 0;

        helper(root , sum ,ans);
        return ans;
    }
};