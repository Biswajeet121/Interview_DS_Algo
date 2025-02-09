
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/maximum-path-sum-from-any-node

class Solution {
  public:
    int solve(Node* root, int &maxi){
        if(root == NULL)
            return 0;
        
        int left = solve(root -> left, maxi);
        int right = solve(root -> right, maxi);
        
        maxi = max(maxi, max(left, right) + root -> data);
        maxi = max(maxi, max(0, left + right) + root -> data);
        
        return max(0, max(left, right)) + root -> data;
    }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};
