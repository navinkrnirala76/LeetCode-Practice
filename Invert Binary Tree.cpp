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
    TreeNode* invertTree(TreeNode* root) {
        //If root is null then return null
        if(root==NULL){
            return NULL;
        }
        //swap the left and right part of the tree (children)
       TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        //Invert the right and left subtree
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
