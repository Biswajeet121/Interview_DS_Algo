/*

    Problem Link : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/?envType=daily-question&envId=2025-01-04

    Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
    Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
    A palindrome is a string that reads the same forwards and backwards.
    A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
    For example, "ace" is a subsequence of "abcde".
  
    Example 1:
    
    Input: s = "aabca"
    Output: 3
    Explanation: The 3 palindromic subsequences of length 3 are:
    - "aba" (subsequence of "aabca")
    - "aaa" (subsequence of "aabca")
    - "aca" (subsequence of "aabca")

  */

  class Solution {
  public:
      int countPalindromicSubsequence(string s) {
          int n = s.size();
  
          unordered_set<char> letters;
          for(int i=0; i<n; i++){
              letters.insert(s[i]);
          }
  
          int result = 0;
          for(char letter: letters){
              int left_idx = -1, right_idx = -1;
              for(int i=0; i<n; i++){
                  if(s[i] == letter){
                      if(left_idx == -1)
                          left_idx = i;
                      right_idx = i;
                  }
              }
              unordered_set<char> st;
              for(int mid = left_idx + 1; mid < right_idx; mid++){
                  st.insert(s[mid]);
              }
              result += st.size();
          }
          return result;
      }
  };
