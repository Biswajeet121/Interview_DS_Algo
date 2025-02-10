
    // Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/k-sum-paths

class Solution {
  public:
    int solve(Node* root, int k, int currSum, unordered_map<int, int> &mp){
        if(root == NULL)
            return 0;
            
        currSum += root -> data;
        int cnt = mp[currSum - k];
        mp[currSum]++;
        
        cnt += solve(root -> left, k, currSum, mp);
        cnt += solve(root -> right, k, currSum, mp);
        mp[currSum]--;
        return cnt;
    }
    int sumK(Node *root, int k) {
        // code here
        unordered_map<int, int>mp;
        mp[0] = 1;
        return solve(root, k, 0, mp);
    }
};
