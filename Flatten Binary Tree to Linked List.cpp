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
    void flatten(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return;

        flatten(root->right); //solve for right subtree first
        flatten(root->left);    

        if(root->left!=NULL){
            TreeNode* r = root->right;
            TreeNode* l = root->left;
            TreeNode* rightMostOfLeft = root->left;

            root->left=NULL; 
            
            while(rightMostOfLeft->right!=NULL){
                rightMostOfLeft = rightMostOfLeft ->right;
            }

            root->right = l;
            rightMostOfLeft->right = r;
        }
        return;
    }
};
