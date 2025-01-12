

    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/trapping-rain-water-1587115621

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n < 3)  return 0;
        
        int mid = 0, val = INT_MIN;
        for(int i=0; i<n; i++){
            if(arr[i] > val){
                val = arr[i];
                mid = i;
            }
        }
        
        int i = 0, leftArea = 0, leftMax = 0;
        while(i < mid){
            leftMax = max(leftMax, arr[i]);
            leftArea += max(0, leftMax - arr[i]);
            i++;
        }
        
        int j = n-1, rightArea = 0, rightMax = 0;
        while(j > mid){
            rightMax = max(rightMax, arr[j]);
            rightArea += max(0, rightMax - arr[j]);
            j--;
        }
        return leftArea + rightArea;
    }
};
