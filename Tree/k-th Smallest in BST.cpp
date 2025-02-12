
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/find-k-th-smallest-element-in-bst


class Solution {
  public:
    // Return the Kth smallest element in the given BST
    void solve(Node* root, int &k, int &ans){
        if(root == NULL)
            return ;
        solve(root -> left, k, ans);
        k--;
        if(k == 0){
            ans = root -> data;
            return;
        }
        solve(root -> right, k, ans);
    }
    int kthSmallest(Node *root, int k) {
        // add code here.
        int ans = -1;
        solve(root, k, ans);
        return ans;
    }
};
