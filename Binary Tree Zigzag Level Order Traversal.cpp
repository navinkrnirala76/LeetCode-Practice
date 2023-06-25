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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> Q;
        int level = 0;
        Q.push(root);

        while (!Q.empty()) {
            size_t size = Q.size();
            vector<int> nodes(size);

            for (int i = 0; i < size; i++) {
                TreeNode* curr = Q.front();
                Q.pop();

                int idx = (level % 2 == 0) ? i : size - 1 - i; 
                nodes[idx] = curr->val;

                if (curr->left) Q.push(curr->left);
                if (curr->right) Q.push(curr->right);
            }
            result.emplace_back(nodes);
            level++;
        }

        return result;
    }
};
