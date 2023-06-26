class Solution {
public:
    TreeNode* construct(vector<int> &postorder,int ps,int pe,vector<int> &inorder, int is,int ie, unordered_map<int,int> &mp){
        if(ps>pe || is>ie) return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int root_idx=mp[postorder[pe]];
        int numleft=root_idx-is;
        root->left=construct(postorder,ps,ps+numleft-1,inorder,is,root_idx-1,mp);
        root->right=construct(postorder,ps+numleft,pe-1,inorder,root_idx+1,ie,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        return construct(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};
