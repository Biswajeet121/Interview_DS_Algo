
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/equilibrium-point-1587115620

class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        int leftSum = 0, rightSum = accumulate(arr.begin(), arr.end(), 0);
        
        for(int i=0; i<n; i++){
            rightSum -= arr[i];
            if(leftSum == rightSum)
                return i;
            leftSum += arr[i];
        }
        return -1;
    }
};
