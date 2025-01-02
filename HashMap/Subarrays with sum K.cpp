/*

  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/subarrays-with-sum-k

  Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.
  
  Examples:
  
  Input: arr = [10, 2, -2, -20, 10], k = -10
  Output: 3
  Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.

*/

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        int n = arr.size(), cnt = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum == k)    cnt++;
            if(mp[sum - k]) cnt+=mp[sum - k];
            mp[sum]++;
        }
        return cnt;
    }
};
