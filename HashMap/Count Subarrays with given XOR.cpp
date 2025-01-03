/*

    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/count-subarray-with-given-xor

    Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.
    
    Examples: 
    
    Input: arr[] = [4, 2, 2, 6, 4], k = 6
    Output: 4
    Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.

*/

    class Solution {
      public:
        long subarrayXor(vector<int> &arr, int k) {
            // code here
            int n = arr.size();
            unordered_map<long, long> mp;
            long Xor = 0, cnt = 0;
            for(int i=0; i<n; i++){
                Xor ^= arr[i];
                if(Xor == k)    cnt++;
                if(mp[Xor ^ k]) cnt += mp[Xor ^ k];
                mp[Xor]++;
            }
            return cnt;
        }
    };
