// Input:
//            3
//          /    \                          
//        4       5
//       /  \      
//     -10   4
// Output: 16
// Explanation:
// Maximum Sum lies between special node 4 and 5.
// 4 + 4 + 3 + 5 = 16.

class Solution
{
public:
    int maxPath(Node *root, int &maxi)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL and root->right == NULL)
        {
            return root->data;
        }

        int left = maxPath(root->left, maxi);
        int right = maxPath(root->right, maxi);

        if (root->left and root->right)
        {
            maxi = max(maxi, left + right + root->data);
            return max(left, right) + root->data;
        }

        if (root->left)
        {
            return left + root->data;
        }
        return right + root->data;
    }
    int maxPathSum(Node *root)
    {
        // code here
        int maxi = INT_MIN;
        int x = maxPath(root, maxi);
        if (root->left and root->right)
        {
            return maxi;
        }

        return max(maxi, x);
    }
};