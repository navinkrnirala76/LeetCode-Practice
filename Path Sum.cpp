
class Solution {
public:
    void solve(TreeNode* &root,int &targetSum,int &sum,bool& ans){
           if(root==NULL)
            return;
        if(root->left==NULL&&root->right==NULL){
            sum+=root->val;
            if(sum==targetSum){
                ans=true;
                }
                sum-=root->val;
                return ;
        }
        sum+=root->val;
        solve(root->left,targetSum,sum,ans);
        solve(root->right,targetSum,sum,ans);
        sum-=root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
     int sum=0;
     bool ans=false;
     solve(root,targetSum,sum,ans);
     return ans;
    }
};
