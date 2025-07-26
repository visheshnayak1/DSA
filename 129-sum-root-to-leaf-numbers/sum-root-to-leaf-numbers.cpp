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
    void dfs(TreeNode* node, int currentNumber , vector<int>& numbers) {
        if(!node) return ;

        currentNumber = currentNumber*10 +node->val;

        if(!node->left &&!node->right) {
            numbers.push_back(currentNumber);
            return;
        }
        dfs(node->left,currentNumber,numbers);
        dfs(node->right,currentNumber, numbers);
    }
    int sumNumbers(TreeNode* root) {
        vector<int> numbers;
        dfs(root,0,numbers);

        int totalSum = 0;
        for(int num: numbers){
            totalSum += num;
        }

        return totalSum;
    }
};