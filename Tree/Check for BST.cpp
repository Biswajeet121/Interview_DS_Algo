
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/check-for-bst

class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool solve(Node* root, int mini, int maxi){
        if(root == NULL)
            return true;
        if((root -> data < maxi) && (root -> data > mini)){
            bool left = solve(root -> left, mini, root -> data);
            bool right = solve(root -> right, root -> data, maxi);
            return left && right;
        }
        else{
            return false;
        }
    }
    bool isBST(Node* root) {
        // Your code here
        return solve(root, INT_MIN, INT_MAX);
    }
};
