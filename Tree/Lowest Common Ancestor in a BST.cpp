
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/lowest-common-ancestor-in-a-bst

class Solution {
  public:
    Node* solve(Node* root, Node* n1, Node* n2){
        if(root -> data < n1 -> data && root -> data < n2 -> data){
            solve(root -> right, n1, n2);
        }
        else if(root -> data > n1 -> data && root -> data > n2 -> data){
            solve(root -> left, n1, n2);
        }
        else{
            return root;
        }
    }
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        return solve(root, n1, n2);
    }
};
