/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    // declare a Hash Map
    
    unordered_map<Node*, Node*> mp;
    
    Node* cloneGraph(Node* node) {
        
        if(node == NULL)
            return NULL;
        
        if(mp.find(node) != mp.end())
            return mp[node];
        
        // create new node
        
        Node* newly_created_node = new Node(node -> val);
        
        mp[node] = newly_created_node;
        
        for(Node* &it : node -> neighbors)
        {
            Node* adjacent = cloneGraph(it);
            
            newly_created_node -> neighbors.push_back(adjacent);
        }
        
        return newly_created_node;
    }
};
