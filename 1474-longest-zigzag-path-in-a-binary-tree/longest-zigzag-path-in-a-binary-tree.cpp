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

    int counter(TreeNode* root,int k,bool isLeft) {
        if(root == nullptr) return k-1;
        if(isLeft) {
            return max(counter(root->left,1,true),counter(root->right,k+1,false));
        }else{
            return max(counter(root->left,k+1,true),counter(root->right,1,false));
        }
        return k-1;
    }
    int longestZigZag(TreeNode* root) {
        return counter(root,0,true);
    }
};