// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.
// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

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
    int solve(TreeNode *root, int &res)
    {
        if (root == NULL)
            return 0;

        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int temp = max(l, r) + 1;
        // int ans = max(temp, 1 + l + r);
        res = max(res, l + r);

        return temp;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int res = INT_MIN;

        solve(root, res);

        return res;
    }
};