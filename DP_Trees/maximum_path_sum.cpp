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

// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.

class Solution
{
public:
    int solve(TreeNode *root, int &res)
    {
        if (!root)
            return 0;
        int l = solve(root->left, res);
        int r = solve(root->right, res);
        // if act as a help node
        int temp = max(max(l, r) + root->val, root->val);
        // if acted as a root itself
        int ans = max(temp, l + r + root->val);
        res = max(res, ans);
        return temp;
    }
    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        solve(root, res);
        return res;
    }
};