/*

    Problem Link : https://leetcode.com/problems/shifting-letters-ii/description/?envType=daily-question&envId=2025-01-05

    You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.
    Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').
    Return the final string after all such shifts to s are applied.
    
    Example 1:
    Input: s = "abc", shifts = [[0,1,0],[1,2,1],[0,2,1]]
    Output: "ace"
    Explanation: Firstly, shift the characters from index 0 to index 1 backward. Now s = "zac".
    Secondly, shift the characters from index 1 to index 2 forward. Now s = "zbd".
    Finally, shift the characters from index 0 to index 2 forward. Now s = "ace".


*/

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int len = s.size();
        vector<int> sum(len + 1, 0);

        for (int i = 0; i < shifts.size(); i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int dir = shifts[i][2];
            int val = (dir == 0 ? -1 : 1);
            sum[start] += val;
            if (end + 1 < len)
                sum[end + 1] -= val;
        }

        for (int i = 1; i < len; i++) {
            sum[i] += sum[i - 1];
        }

        for (int i = 0; i < len; i++) {
            int shift = sum[i];
            s[i] = 'a' + (s[i] - 'a' + shift % 26 + 26) % 26;
        }

        return s;
    }
};
