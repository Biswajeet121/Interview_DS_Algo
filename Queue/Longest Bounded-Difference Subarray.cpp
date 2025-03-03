
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/queue-and-deque-gfg-160/problem/longest-bounded-difference-subarray

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size(), i = 0;
        vector<int> ans;
        pair<int, int> length = {0, 0};
        deque<int> maxDq, minDq;
        
        for(int j=0; j<n; j++){
            while(!maxDq.empty() && arr[j] > maxDq.back()){
                maxDq.pop_back();
            }
            while(!minDq.empty() && arr[j] < minDq.back()){
                minDq.pop_back();
            }
            
            maxDq.push_back(arr[j]);
            minDq.push_back(arr[j]);
            
            if(abs(maxDq.front() - minDq.front()) <= x){
                if(j-i+1 > length.first){
                    length.first = j-i+1;
                    length.second = i;
                }
            }
            else{
                if(arr[i] == maxDq.front())
                    maxDq.pop_front();
                if(arr[i] == minDq.front())
                    minDq.pop_front();
                i++;
            }
        }
        
        for(int i=length.second; i<length.second + length.first; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
