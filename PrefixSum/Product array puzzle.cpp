
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/product-array-puzzle4525

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        int n = arr.size();
        int pro = 1, zero = 0, zeroIdx = -1;
        vector<int> ans(n, 0);
        
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                zero++;
                if(zero == 2)
                    return ans;
                zeroIdx = i;
            }
            else{
                pro *= arr[i];
            }
        }
        if(zero){
            ans[zeroIdx] = pro;
            return ans;
        }
        for(int i=0; i<n; i++){
            ans[i] = (pro / arr[i]);
        }
        
        return ans;
    }
};
