
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/find-unique-number

class Solution {
  public:
    int findUnique(vector<int> &arr) {
        // code here
        int n = arr.size(), ans = 0;
        for(int i=0; i<n; i++){
            ans ^= arr[i];
        }
        return ans;
    }
};
