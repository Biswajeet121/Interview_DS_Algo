/*

    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/pair-in-array-whose-sum-is-closest-to-x1124
    
    Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a<=b whose sum is closest to target.
    Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.
    
    Examples:
    
    Input: arr[] = [10, 30, 20, 5], target = 25
    Output: [5, 20]
    Explanation: As 5 + 20 = 25 is closest to 25.

  */
class Solution{
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        int n = arr.size(); 
        if(n == 1)  return {};
        vector<int> ans(2, 0);
        sort(arr.begin(), arr.end());
        int diff = INT_MAX, absVal = INT_MIN;
        
        int i = 0, j = n - 1;
        while(i < j){
            if(arr[i] + arr[j] >= target){
                if(diff == abs(target - (arr[i] + arr[j]))){
                    if(abs(arr[i] - arr[j] > abs(ans[0] - ans[1]))){
                        ans[0] = arr[i];
                        ans[1] = arr[j];
                    }
                }
                if(diff > abs(target - (arr[i] + arr[j]))){
                    diff = abs(target - (arr[i] + arr[j]));
                    ans[0] = arr[i];
                    ans[1] = arr[j];
                }
                j--;
            }
            else{
                if(diff > abs(target - (arr[i] + arr[j]))){
                    diff = abs(target - (arr[i] + arr[j]));
                    ans[0] = arr[i];
                    ans[1] = arr[j];
                }
                i++;
            }
        }
        return ans;
    }
};
