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
    void insert(TreeNode* root, map<TreeNode*, vector<pair<TreeNode*, char>>>& mpp) {
        if (root == nullptr) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                mpp[node].push_back({node->left, 'L'});
                mpp[node->left].push_back({node, 'U'});
            }
            if (node->right) {
                q.push(node->right);
                mpp[node].push_back({node->right, 'R'});
                mpp[node->right].push_back({node, 'U'});
            }
        }
    }

    bool findPath(TreeNode* root, TreeNode* dest, map<TreeNode*, vector<pair<TreeNode*, char>>>& mpp, set<TreeNode*>& visited, string& path) {
        if (root == nullptr) return false;
        if (root == dest) return true;
        visited.insert(root);
        for (auto& neighbor : mpp[root]) {
            if (visited.find(neighbor.first) == visited.end()) {
                path.push_back(neighbor.second);
                if (findPath(neighbor.first, dest, mpp, visited, path)) {
                    return true;
                }
                path.pop_back();
            }
        }
        visited.erase(root);
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        map<TreeNode*, vector<pair<TreeNode*, char>>> mpp;
        insert(root, mpp);

        TreeNode* start = nullptr;
        TreeNode* dest = nullptr;
        for (auto it : mpp) {
            if (it.first->val == startValue) start = it.first;
            if (it.first->val == destValue) dest = it.first;
            if (start && dest) break;
        }

        set<TreeNode*> visited;
        string path = "";
        findPath(start, dest, mpp, visited, path);
        return path;
    }
};