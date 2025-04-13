
  Problem Link : https://www.geeksforgeeks.org/problems/clone-graph/1

class Solution {
  public:
    unordered_map<Node*, Node*> present;
    Node* cloneGraph(Node* node) {
        // code here
        if(!node)   
            return NULL;
        if(present.find(node) != present.end())
            return present[node];
        Node* clone = new Node(node -> val);
        present[node] = clone;
        for(auto n : node -> neighbors){
            clone -> neighbors.push_back(cloneGraph(n));
        }
        return clone;
    }
};
