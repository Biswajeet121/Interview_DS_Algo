

Problem Link : https://leetcode.com/problems/counting-words-with-a-given-prefix/description/?envType=daily-question&envId=2025-01-09

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size(), m = pref.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(pref.size() > words[i].size())
                continue;
            if(pref[0] == words[i][0]){
                string s = words[i].substr(0, m);
                if(s == pref)
                    cnt++;
            }
        }
        return cnt;
    }
};
