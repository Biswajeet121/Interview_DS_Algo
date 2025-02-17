
    problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/heap-gfg-160/problem/k-largest-elements4206

vector<int> kLargest(vector<int>& arr, int k) {
      // Your code here
      int n = arr.size();
      vector<int> ans(k, 0);
      priority_queue<int, vector<int>, greater<int>> pq;
      
      for(int i=0; i<n; i++){
          pq.push(arr[i]);
          if(pq.size() > k)
              pq.pop();
      }
      
      for(int i=0; i<k; i++){
          ans[k-i-1] = pq.top();
          pq.pop();
      }
      return ans;
  };
