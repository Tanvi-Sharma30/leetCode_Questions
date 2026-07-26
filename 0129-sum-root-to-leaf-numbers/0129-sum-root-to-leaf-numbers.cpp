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
    int numSum(TreeNode* root, int num){
        if(root==NULL) return 0;
        num = num*10 + root->val;
        if(root->left==NULL && root->right==NULL) return num;

        return numSum(root->left,num)+ numSum(root->right,num);
    }
    int sumNumbers(TreeNode* root) {
        int num=0;
        return numSum(root,num);
    }
};