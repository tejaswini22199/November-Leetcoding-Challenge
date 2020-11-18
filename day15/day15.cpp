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
 Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range [low, high].
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)
            return 0;
        else if(root->val<low)
            return rangeSumBST(root->right,low,high);
        else if(root->val>high)
            return rangeSumBST(root->left,low,high);
        else
            return root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};