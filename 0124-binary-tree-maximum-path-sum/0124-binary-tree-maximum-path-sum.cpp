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
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return maxSum;
    }
    int maxPath(TreeNode* root){
        if(root == NULL) return 0;
        int ls = max(0, maxPath(root->left));
        int rs = max(0, maxPath(root->right));
        maxSum = max(maxSum, (ls+rs+root->val));

        return max(ls, rs) + root->val;
    }
};