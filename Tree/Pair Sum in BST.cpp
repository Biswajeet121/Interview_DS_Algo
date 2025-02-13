
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/find-a-pair-with-given-target-in-bst


class Solution {
  public:
    void solve(Node* root, int target, unordered_map<int, int>& mp, bool &check){
        if(root == NULL)
            return ;
        if(mp.count(target - root -> data)){
            check = true;
            return ;
        }
        mp[root -> data] = 1;
        solve(root -> left, target, mp, check);
        solve(root -> right, target, mp, check);
    }
    bool findTarget(Node *root, int target) {
        // your code here.
        bool check = false;
        unordered_map<int, int>mp;
        solve(root, target, mp, check);
        return check;
    }
};
