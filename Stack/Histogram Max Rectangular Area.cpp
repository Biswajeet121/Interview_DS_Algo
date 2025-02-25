
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/maximum-rectangular-area-in-a-histogram-1587115620
  
class Solution {
  public:
    vector<int> nextSmaller(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=n-1; i>=0; i--){
            int val = arr[i];
            while(st.top() != -1 && arr[st.top()] >= val){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> arr, int n){
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=0; i<n; i++){
            int val = arr[i];
            while(st.top() != -1 && arr[st.top()] >= val){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        vector<int> next(n);
        next = nextSmaller(arr, n);
        
        vector<int> prev(n);
        prev = prevSmaller(arr, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++){
            int l = arr[i];
            if(next[i] == -1)
                next[i] = n;
            int b = next[i] - prev[i] - 1;   
            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }
};
