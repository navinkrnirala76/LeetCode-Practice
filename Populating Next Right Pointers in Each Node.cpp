/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> q;
        vector<vector<Node*>> v;
        q.push(root);
        int level = 0;

        while(!q.empty()) {
            int k = q.size();
            while(k--) {
                Node* x = q.front();
                q.pop();
                if(level >= v.size()) v.push_back({x});
                else v[level].push_back(x);

                if(x->left != NULL) q.push(x->left);
                if(x->right != NULL) q.push(x->right);
            }
            level++;
        }

        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v[i].size(); j++) {
                if(j == v[i].size()-1) {
                    v[i][j]->next = NULL;
                }
                else {
                    v[i][j]->next = v[i][j+1];
                }
            }
        }
        return root;
    }
};
