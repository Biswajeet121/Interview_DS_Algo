

    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/diameter-of-binary-tree

class Solution {
  public:
    int solve(Node* root, int &diameter){
        if(root == NULL)    return 0;
        
        int left = solve(root -> left, diameter);
        int right = solve(root -> right, diameter);
        diameter = max(diameter, left + right);
        
        return max(left, right) + 1;
    }
    int diameter(Node* root) {
        // Your code here
        int diameter = INT_MIN;
        solve(root, diameter);
        return diameter;
    }
};
