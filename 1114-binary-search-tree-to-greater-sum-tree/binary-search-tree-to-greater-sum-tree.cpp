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
    TreeNode* bstToGst(TreeNode* root) {
        solve(root, 0);
        return root;
    }

    private :
    int solve(TreeNode* root, int sum) {
        if(root == NULL) return 0;

        int right = solve(root->right ,sum);
        int curr_val = root->val;
        root->val = curr_val+sum+right;
        int left = solve(root->left ,root->val);
        return curr_val+right+left;

    }
};