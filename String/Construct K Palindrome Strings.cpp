

    Problem Link : https://leetcode.com/problems/construct-k-palindrome-strings/description/?envType=daily-question&envId=2025-01-11

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n < k)
            return false;
        if(n == k)
            return true;
        
        vector<int> arr(26, 0);
        for(int i=0; i<n; i++){
            arr[s[i] - 'a']++;
        }

        int oddCnt = 0;
        for(int i=0; i<26; i++){
            if(arr[i] % 2 == 1){
                oddCnt++;
            }
        }
        return oddCnt <= k;
    }
};
