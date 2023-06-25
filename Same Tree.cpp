class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(q==NULL&&p==NULL)
            return true;
        if(q==NULL&&p!=NULL)
            return false;
        if(q!=NULL &&p==NULL)
            return false;
        return ((q->val==p->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right));
    }
};
