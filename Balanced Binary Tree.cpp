class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(height(root)==-1) return false; // if it is balanced then height will be calculated 
        //or it will just return -1
        return true;
    }
    int height(TreeNode* root){
        if(!root) return 0;
        int lefth=height(root->left);
        if(lefth==-1) return -1;
        int righth=height(root->right);
        if(righth==-1) return -1;
        if(abs(lefth-righth)>1) return -1;
        return max(lefth,righth)+1;
    }
};
