class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* &root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        
        if(root->val==p->val)
            return p;
        if(root->val==q->val)
            return q;
        TreeNode* leftans=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightans=lowestCommonAncestor(root->right,p,q);
        
        if(leftans==NULL&&rightans==NULL)
            return NULL;
        if(leftans!=NULL&&rightans==NULL)
            return leftans;
        if(leftans==NULL&&rightans!=NULL)
            return rightans;
        else
            return root;
    }
};
