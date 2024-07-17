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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> list ;
        for(int i=0;i<to_delete.size();i++){
            if(root->val==to_delete[i]){
                break;
            }
            if(i==to_delete.size()-1){
                list.push_back(root);
            }
        }
        help(root,list,to_delete);
        return list;
    }
    TreeNode* help(TreeNode* root,vector<TreeNode*>& list,vector<int>& to_delete){
        if(root==NULL){
            return NULL;
        }
        TreeNode* left = help(root->left,list,to_delete);
        TreeNode* right = help(root->right,list,to_delete);
        if(left==NULL){
            root->left=NULL;
        }
        if(right==NULL){
            root->right=NULL;
        }
        for(int i=0;i<to_delete.size();i++){
            if(root->val==to_delete[i]){
                if(root->left!=NULL){
                    list.push_back(root->left);
                }
                if(root->right!=NULL){
                    list.push_back(root->right);
                }
                return NULL;
            }
        }
        return root;
    }
};