
  Problem Link : https://www.geeksforgeeks.org/problems/maximize-partitions-in-a-string/1

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int n = s.size(), cnt = 0;
        vector<int> v(26, 0);
        for(int i=0; i<n; i++){
            v[s[i] - 'a'] = i;
        }
        
        for(int i=0; i<n; i++){
            int j = i, end = v[s[i] - 'a'];
            for(j=i; j<end; j++){
                end = max(end, v[s[j] - 'a']);
            }
            cnt++;
            i=j;
        }
        return cnt;
    }
};
