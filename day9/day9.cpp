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
 Given the root of a binary tree, find the maximum value V for which there exist different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B
 */
class Solution {
public:
    int maxAncestorHelper(TreeNode* root,int curr_max,int curr_min)
    {
        if(root==NULL)
            return curr_max-curr_min;
        curr_max=max(curr_max,root->val);
        curr_min=min(curr_min,root->val);
        int left_max=maxAncestorHelper(root->left,curr_max,curr_min);
        int right_max=maxAncestorHelper(root->right,curr_max,curr_min);
        return max(left_max,right_max);
                  
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL)
            return 0;
        int curr_max=root->val;
        int curr_min=root->val;
        return maxAncestorHelper(root,curr_max,curr_min);
        
        
    }
};