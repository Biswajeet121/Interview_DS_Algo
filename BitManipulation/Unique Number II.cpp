
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/bit-manipulation-gfg-160/problem/finding-the-numbers0215

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int n = arr.size(), first = 0, second = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            if(mp[arr[i]])
                mp[arr[i]]--;
            else
                mp[arr[i]]++;
        }
        
        for(auto x: mp){
            if(x.second == 1 && first == 0){
                first = x.first;
                continue;
            }
            if(x.second == 1 && first != 0){
                second = x.first;
            }
        }
        if(first < second)
            return {first, second};
        else
            return {second, first};
    }
};
