class Solution {
	public:
		Node* connect(Node* root) {
			if(!root) return NULL;

			vector<vector<Node*>> lvl;
			queue <Node*> q;
			q.push(root);

			while(!q.empty()){
				int size = q.size();
				vector <Node*> temp;

				for(int i = 0 ; i < size ; i++){
					Node* node = q.front();
					q.pop();
					if(node -> left) q.push(node -> left);
					if(node -> right) q.push(node -> right);
					temp.push_back(node);
				}

				temp.push_back(NULL);
				lvl.push_back(temp);
			} 

			for(int i = 0 ; i < lvl.size() ; i++){
				for(int j = 0 ; j < lvl[i].size() - 1 ; j++) lvl[i][j] -> next = lvl[i][j + 1];
			}

			return root;
		}
	};
