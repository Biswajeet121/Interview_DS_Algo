
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/longest-distinct-characters-in-string5848

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size(), maxi = INT_MIN;
        vector<int> arr(26, 0);
        
        int i = 0, j = 0;
        while(j < n){
            int idx = s[j] - 'a';
            if(arr[idx] == 0){
                arr[idx] = 1;
                maxi = max(maxi, j - i + 1);
            }
            else{
                while(arr[idx] != 0){
                    arr[s[i] - 'a'] = 0;
                    i++;
                }
                arr[idx] = 1;
                maxi = max(maxi, j - i + 1);
            }
            j++;
        }
        return maxi;
    }
};
