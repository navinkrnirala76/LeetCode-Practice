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
private:
    int maxPathSumHelper(TreeNode* root, int& res) {
        if (root == nullptr) {
            return 0;
        }
        
        int leftSum = maxPathSumHelper(root->left, res);
        int rightSum = maxPathSumHelper(root->right, res);
        
        int maxChildSum = max(leftSum, rightSum);
        
        int maxRootSum = max(maxChildSum + root->val, root->val);
        int maxTreeSum = max(maxRootSum, leftSum + rightSum + root->val);
        
        res = max(res, maxTreeSum);
        
        return maxRootSum;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSumHelper(root, res);
        return res;
    }
};
