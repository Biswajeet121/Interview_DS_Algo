/*

    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-pairs-whose-sum-is-less-than-target

    Given an array arr[] and an integer target. You have to find the number of pairs in the array whose sum is strictly less than the target.
    
    Examples:
    
    Input: arr[] = [7, 2, 5, 3], target = 8
    Output: 2
    Explanation: There are 2 pairs with sum less than 8: (2, 5) and (2, 3). 

*/

class Solution{
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        int n = arr.size(), cnt = 0;
        sort(arr.begin(), arr.end());
        
        int i = 0, j = n - 1;
        while(i < j){
            if(arr[i] + arr[j] >= target){
                j--;
            }
            else{
                cnt += (j - i);
                i++;
            }
        }
        return cnt;
    }
