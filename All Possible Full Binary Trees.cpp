
class Solution {
public:
    vector<TreeNode*>solve(int n)
    {
        if (n == 1) return { new TreeNode() };
        
        vector<TreeNode*>currList;
        int remainingNodes = n - 1; //1 node will be fixed as root
        //==========================================================================================
        //need only odd no. of nodes in left and right, that's why (+=2)
        for (int left = 1; left <= remainingNodes; left += 2) 
        {
            int right = remainingNodes - left;
            //=====================================================
            vector<TreeNode*>leftPossible = solve(left);
            vector<TreeNode*>rightPossible = solve(right);
            for (int i = 0; i < leftPossible.size(); i++)
            {
                for (int j = 0; j < rightPossible.size(); j++)
                {
                    TreeNode* root = new TreeNode();
                    root->left = leftPossible[i];
                    root->right = rightPossible[j];
                    currList.push_back(root);
                }
            }
            //=======================================================
        }
        //==================================================================================================
        return currList;
    }
    vector<TreeNode*> allPossibleFBT(int n) 
    {
        if (n % 2 == 0) return {};
        vector<TreeNode*>ans = solve(n);
        return ans; 
    }
};
