
class Solution {
public:
    int checkBalanse(TreeNode* root, bool& res) {
        // if root = null or result already false
        if (!root || !res) return 0;

        // find height for left and right nodes
        int left_height = checkBalanse(root->left, res);
        int right_height = checkBalanse(root->right, res);
        if (abs(left_height - right_height) > 1)
            res = false;
        
        return max(left_height, right_height) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        checkBalanse(root, res);

        return res;
    }
};