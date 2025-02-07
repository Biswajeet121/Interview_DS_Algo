
    // Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/inorder-traversal

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void solve(Node* root, vector<int>& ans){
        if(root == NULL)
            return ;
        solve(root -> left, ans);
        ans.push_back(root -> data);
        solve(root -> right, ans);
    }
    vector<int> inOrder(Node* root) {
        // Your code here
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};
