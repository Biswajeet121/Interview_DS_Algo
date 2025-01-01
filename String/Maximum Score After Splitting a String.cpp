/*

  Problem Link : https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2025-01-01

  Problem Statement: 
  Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).
  
  The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.
  
  Example 1:
  
  Input: s = "011101"
  Output: 5 
  Explanation: 
  All possible ways of splitting s into two non-empty substrings are:
  left = "0" and right = "11101", score = 1 + 4 = 5 
  left = "01" and right = "1101", score = 1 + 3 = 4 
  left = "011" and right = "101", score = 1 + 2 = 3 
  left = "0111" and right = "01", score = 1 + 1 = 2 
  left = "01110" and right = "1", score = 2 + 1 = 3
*/

************************************************************ C++ ************************************************************

  // Approach 1:
  class Solution {
  public:
      int maxScore(string s) {
          int n = s.size();
          int zero = 0, one = 0;
          for(int i=0; i<n; i++){
              if(s[i] == '1')   one++;
          }
          
          int maxi = INT_MIN;
          for(int i=0; i<n-1; i++){
              if(s[i] == '0')   zero++;
              else   one--;
              maxi = max(maxi, zero + one);
          }
          return maxi;
      }
  };
