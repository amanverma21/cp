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
private:
    bool f(TreeNode*root){
        if(!root){
            return 1;
        }
        
        if(!root->left && !root->right){
            if(root->val==0){
                return false;
            }
            else if(root->val==1){
                return true;
            }
        }
        bool left=f(root->left);
        bool right=f(root->right);

        if(root->val==2){
            return left || right;
        }
        else if(root->val==3){
            return left && right;
        }

        return true;
    }
public:
    bool evaluateTree(TreeNode* root) {
        return f(root);
    }
};