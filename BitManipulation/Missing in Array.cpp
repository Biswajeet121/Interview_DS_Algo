
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/missing-number-in-array1416

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size(), ans = 0;
        for(int i=0; i<n+2; i++){
            if(i < n)
                ans ^= arr[i];
            if(i > 0)
                ans ^= i;
        }
        return ans;
    }
};
