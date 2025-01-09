

Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/subarray-with-given-sum-1587115621

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int n = arr.size();
        long long sum = 0;
        int i=0, j=0;
        while(j<n){
            sum += arr[j];
            if(sum == target)   return {i+1, j+1};
            
            while(i < j && sum > target){
                sum -= arr[i];
                i++;
                if(sum == target)   return {i+1, j+1};
            }
            j++;
        }
        return {-1};
    }
};
