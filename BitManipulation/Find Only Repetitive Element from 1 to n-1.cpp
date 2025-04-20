
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/find-repetitive-element-from-1-to-n-1

class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        // code here
        int n = arr.size(), half = n/2;
        int sum = (n-1) * half, actualSum = 0;
        for(int i=0; i<n; i++){
            actualSum += arr[i];
        }
        return actualSum - sum;
    };
}
