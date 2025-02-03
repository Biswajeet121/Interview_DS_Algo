
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/height-of-binary-tree

class Solution {
  public:
    // Function to find the height of a binary tree.
    int solve(Node* root){
        if(root == NULL){
            return 0;
        }
        int left = solve(root -> left);
        int right = solve(root -> right);
        int ans = max(left, right) + 1;
        return ans;
    }
    int height(Node* node) {
        // code here
        return solve(node)-1;
    }
};
