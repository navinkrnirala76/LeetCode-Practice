class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
           int sz=q.size();
           vector<int>v;
           while(sz--){
               TreeNode * f=q.front();
               v.push_back(q.front()->val);
               q.pop();
               if(f->left)q.push(f->left);
               if(f->right)q.push(f->right);

           }
           ans.push_back(v);
        }
        return ans;
    }
};
