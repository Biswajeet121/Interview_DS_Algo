
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/mirror-tree

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void solve(Node* root){
        if(root == NULL)
            return;
        
        solve(root -> left);
        solve(root -> right);
        
        Node* l = root -> left;
        Node* r = root -> right;
        
        root -> left = r;
        root -> right = l;
    }
    void mirror(Node* node) {
        // code here
        solve(node);
    }
};
