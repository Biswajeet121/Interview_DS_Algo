
    Problem Link : https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13

class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), sum = 0;
        vector<int> arr(26, 0);

        for(int i=0; i<n; i++){
            arr[s[i] - 'a']++;
        }
        
        for(int i=0; i<26; i++){
            if(arr[i] == 0) continue;
            if(arr[i] % 2)  sum += 1;
            else    sum += 2;
        }
        return sum;
    }
};
