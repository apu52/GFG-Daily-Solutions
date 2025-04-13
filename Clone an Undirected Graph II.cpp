class Solution {
  public:
map<Node*,Node*>clone;
    Node* cloneGraph(Node* node) {
        if(!node)return node;
        if(clone.count(node))return clone[node];
        Node* root = new Node(node->val);
        clone[node]=root;
        for(Node* neighbor : node->neighbors) 
            (root->neighbors).push_back(cloneGraph(neighbor));
        return root;
    }
    
};
