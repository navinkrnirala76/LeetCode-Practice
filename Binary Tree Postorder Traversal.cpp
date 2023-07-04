
class Solution{
    public:
        vector<int> postorderTraversal(TreeNode* root){
            vector<int> nodes;
            Postorder(root, nodes);
            return nodes;
        }
    
    private:
        void Postorder(TreeNode* root,vector<int>& nodes){
            if(root == NULL) return ;

            Postorder(root->left, nodes);
            Postorder(root->right, nodes);
            nodes.push_back(root->val);
        }
};  
