
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/queue-and-deque-gfg-160/problem/maximum-of-all-subarrays-of-size-k3101

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        deque<int> dq;
        vector<int> res;
        for(int i=0; i<n; i++){
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            while(!dq.empty() && arr[i] > arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k-1){
                res.push_back(arr[dq.front()]);
            }
        }
        return res;
    }
};
