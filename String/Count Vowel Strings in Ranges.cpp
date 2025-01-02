/*

  Problem Link : https://leetcode.com/problems/count-vowel-strings-in-ranges/description/?envType=daily-question&envId=2025-01-02

  You are given a 0-indexed array of strings words and a 2D array of integers queries.
  
  Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
  
  Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
  
  Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.
  
   
  
  Example 1:
  
  Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
  Output: [2,3,0]
  Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
  The answer to the query [0,2] is 2 (strings "aba" and "ece").
  to query [1,4] is 3 (strings "ece", "aa", "e").
  to query [1,1] is 0.
  We return [2,3,0].

  */

  class Solution {
  public:
      vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
          int n = words.size(), m = queries.size();
          vector<int> check(n, 0), ans(m);;
          for(int i=0; i<n; i++){
              string s = words[i];
              int l = s.size() - 1;
              if((s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u') &&
                 (s[l]=='a' || s[l]=='e' || s[l]=='i' || s[l]=='o' || s[l]=='u')){
                      check[i] = 1;
              }
              if(i > 0)  check[i] += check[i-1];
          }

          for(int i=0; i<m; i++){
              int start = queries[i][0], end = queries[i][1];
              ans[i] = check[end] - ((start > 0) ? check[start - 1] : 0);
          }
          return ans;
      }
  };
