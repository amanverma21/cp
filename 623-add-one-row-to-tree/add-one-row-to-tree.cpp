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
class Solution
{
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (!root)
        {
            TreeNode *node = new TreeNode(val);
            return node;
        }
        if (depth == 1)
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<pair<pair<TreeNode *, TreeNode *>, int>> q; //   root   children    position
        q.push({{NULL, root}, -1});
        while (!q.empty() && (depth > 1))
        {
            int n = q.size();
            while (n--)
            {
                auto front = q.front();
                q.pop();
                auto rootElement = front.first.second;
                if (rootElement)
                {
                    q.push({{rootElement, rootElement->left}, 0});
                    q.push({{rootElement, rootElement->right}, 1});
                }
            }
            depth--;
        }

        // cout << q.size();
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            auto curRoot =  node.first.first;
            auto childRoot = node.first.second;
            TreeNode *newNode = new TreeNode(val);
            if (node.second == 0)
            {
                curRoot->left = newNode;
                newNode->left = childRoot;
            }
            else
            {
                curRoot->right = newNode;
                newNode->right = childRoot;
            }
        }

        return root;
    }
};