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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //int i=0;
        vector<vector<int>> v;
         if(root==NULL) return v;
        queue<TreeNode*>q;
       
        q.push(root);
        q.push(NULL);
        vector<int>v1;
        while(!q.empty()){
            TreeNode *cur=q.front();
            q.pop();
            
            if(cur==NULL){
                v.push_back(v1);
                v1.resize(0);
                if (q.size() > 0) {
                    q.push(NULL);
                }
            }else{
                    v1.push_back(cur->val);
            if(cur->left!=NULL)q.push(cur->left);
            if(cur->right!=NULL)q.push(cur->right);
            }
            
            
        }
        stack<vector<int>>s;
        int n=v.size();
        for(int i=0;i<n;i++){
            s.push(v[i]);
        }
        vector<vector<int>> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
