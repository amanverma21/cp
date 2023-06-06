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
    void findPreMoris(TreeNode* root,vector<TreeNode*> &preOrder){
        if(root==NULL) return;
        while(root!=NULL){
            if(root->left==NULL){
                preOrder.push_back(root);
                root=root->right;
            }
            else{
                TreeNode* prev=root->left;
                while(prev->right!=NULL && prev->right!=root){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=root;
                    preOrder.push_back(root);
                    root=root->left;
                }
                else{ // prev->right==root
                    prev->right=NULL;
                    root=root->right;
                }
            }
        }
    }
    
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> preOrder;
        TreeNode* cur=root;
        findPreMoris(root,preOrder);
        for(int i=1;i<preOrder.size();i++){
            root->left=NULL;
            root->right=preOrder[i];
            root=preOrder[i];
        }
        // root=cur;
    }
};