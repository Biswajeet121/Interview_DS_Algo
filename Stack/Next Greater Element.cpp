
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/next-larger-element-1587115620
  
class Solution {
  public:
    // Function to find the next greater element for each element of the array.
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int> res(n,-1);
        stack<int> st;
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            while(st.empty()==false && st.top()<=arr[i])
                st.pop();
            
            if(st.empty()==false)
                res[i]=st.top();
            
            st.push(arr[i]);
        }
        return res;
    }
};
