Problem Link : https://leetcode.com/problems/string-matching-in-an-array/description/?envType=daily-question&envId=2025-01-07
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i != j){
                    if(words[j].find(words[i]) != string::npos){
                        ans.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
