
  Problem Link : https://leetcode.com/problems/word-subsets/description/?envType=daily-question&envId=2025-01-10

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size();
        vector<vector<int>> arr1(n, vector<int>(26, 0));
        vector<int> maxFreq(26, 0); // Maximum frequency for each letter across words2
        vector<string> ans;

        // Build frequency map for words1
        for (int i = 0; i < n; i++) {
            for (char c : words1[i]) {
                arr1[i][c - 'a']++;
            }
        }

        // Build max frequency map for words2
        for (int i = 0; i < m; i++) {
            vector<int> freq(26, 0);
            for (char c : words2[i]) {
                freq[c - 'a']++;
                maxFreq[c - 'a'] = max(maxFreq[c - 'a'], freq[c - 'a']);
            }
        }

        // Check if words in words1 are universal
        for (int i = 0; i < n; i++) {
            bool isUniversal = true;
            for (int j = 0; j < 26; j++) {
                if (arr1[i][j] < maxFreq[j]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                ans.push_back(words1[i]);
            }
        }

        return ans;
    }
};
