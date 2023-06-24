class Solution {
public:
    vector<TreeNode*> generateTrees(int n, int s = 1) {
        vector<TreeNode*> ans;
        if(n < s)
            return {nullptr};
			
		// Consider every number in range [s,n] as root 
        for(int i=s; i<=n; i++) {
		
			// generate all possible trees in range [s,i)
            for(auto left: generateTrees(i-1, s)) {
			
				// generate all possible trees in range (i,e]
                for(auto right: generateTrees(n, i+1))
				
					// make new trees with i as the root
                    ans.push_back(new TreeNode(i, left, right));
            }
        }
        return ans;
    }
};
