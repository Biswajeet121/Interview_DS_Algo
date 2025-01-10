
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-distinct-elements-in-every-window

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        int n = arr.size(), cnt = 0;
        unordered_map<int, int> mp;
        vector<int> ans;
        
        int i = 0, j = 0;
        while(j < n){
            if(mp[arr[j]] == 0){
                mp[arr[j]]++;
                cnt++;
            }
            else{
                mp[arr[j]]++;
            }
            if(j - i + 1 == k){
                ans.push_back(cnt);
                if(mp[arr[i]] == 1){
                    cnt--;
                }
                mp[arr[i++]]--;
            }
            j++;
        }
        return ans;
    }
};
