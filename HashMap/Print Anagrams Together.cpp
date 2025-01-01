/*

  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/hashing-gfg-160/problem/print-anagrams-together

  Problem Statement: 
  Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

  Note: The final output will be in lexicographic order.
  
  Examples:
  
  Input: arr[] = ["act", "god", "cat", "dog", "tac"]
  Output: [["act", "cat", "tac"], ["god", "dog"]]
  Explanation: There are 2 groups of anagrams "god", "dog" make group 1. "act", "cat", "tac" make group 2.

*/

************************************************************ C++ ************************************************************

  // Approach 1:
  vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        int n = arr.size();
        vector<vector<string>> ans;
        
        vector<pair<string, int>> store;
        for(int i=0; i<n; i++){
            string s = arr[i];
            sort(s.begin(), s.end());
            store.push_back({s, i});
        }
        sort(store.begin(), store.end());
        
        vector<string> temp;
        for(int i=0; i<n; i++){
            if(i==0 || store[i-1].first == store[i].first){
                temp.push_back(arr[store[i].second]);
            }
            else{
                ans.push_back(temp);
                temp.clear();
                temp.push_back(arr[store[i].second]);
            }
        }
        ans.push_back(temp);
        
        return ans;
    }

    //Approach 2
    vector<vector<string>> anagrams(vector<string>& arr) {
      unordered_map<string, vector<string>> groupedAnagrams;
      for (const string& word : arr) {
          string sortedWord = word;
          sort(sortedWord.begin(), sortedWord.end());
          groupedAnagrams[sortedWord].push_back(word);
      }
  
      vector<vector<string>> ans;
      for (auto& group : groupedAnagrams) {
          ans.push_back(group.second);
      }
  
      return ans;
  }

  //Approach 3
  vector<vector<string>> anagrams(vector<string>& arr) {
    unordered_map<string, vector<string>> groupedAnagrams;
    for (const string& word : arr) {
        vector<int> charCount(26, 0);
        for (char c : word) {
            charCount[c - 'a']++;
        }
        string key;
        for (int count : charCount) {
            key += to_string(count) + '#'; // Unique representation
        }
        groupedAnagrams[key].push_back(word);
    }

    vector<vector<string>> ans;
    for (auto& group : groupedAnagrams) {
        ans.push_back(group.second);
    }

    return ans;
}

