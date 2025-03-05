
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/longest-string-chain
class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        // Code here
        int n = words.size();
        unordered_map<string, int> mp;
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });
        
        int maxi = 1;
        for(int i=0; i<n; i++){
            mp[words[i]] = 1;
            for(int j=0; j<words[i].size(); j++){
                string s = words[i].substr(0, j) + words[i].substr(j+1);
                if(mp[s]){
                    mp[words[i]] = max(mp[words[i]], mp[s]+1);  
                }
            }
            maxi = max(maxi, mp[words[i]]);
        }
        return maxi;
    }
};
