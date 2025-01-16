
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/largest-subarray-of-0s-and-1s

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int maxLength = 0;
        
        for(int i=0; i<n; i++){
            sum += (arr[i] == 0 ? -1 : 1);
        
            if(sum == 0)
                maxLength = max(maxLength, i + 1);
            
            if(mp.find(sum) != mp.end())
                maxLength = max(maxLength, i - mp[sum]);
            else
                mp[sum] = i;
        }
        return maxLength;
    }
};
