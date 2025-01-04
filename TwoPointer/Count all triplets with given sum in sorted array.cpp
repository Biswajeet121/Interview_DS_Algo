/*

    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-all-triplets-with-given-sum-in-sorted-array

    Problem Statement: 
    Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k.
    
    Examples:
    
    Input: arr[] = [-3, -1, -1, 0, 1, 2], target = -2
    Output: 4
    Explanation: Two triplets that add up to -2 are:
    arr[0] + arr[3] + arr[4] = (-3) + 0 + (1) = -2
    arr[0] + arr[1] + arr[5] = (-3) + (-1) + (2) = -2
    arr[0] + arr[2] + arr[5] = (-3) + (-1) + (2) = -2
    arr[1] + arr[2] + arr[3] = (-1) + (-1) + (0) = -2

*/

    class solution{
    public:
      int countTriplets(vector<int> &arr, int target) {
          // Code Here
          int n = arr.size(), cnt = 0;
          
          for(int i=0; i<n-2; i++){
              int j=i+1, k=n-1;
              while(j < k){
                  if((arr[i] + arr[j] + arr[k]) == target){
                      cnt++;
                      int temp = j + 1;
                      while(temp < k && arr[temp] == arr[temp - 1]){
                          cnt++;
                          temp++;
                      }
                      k--;
                  }
                  else if((arr[i] + arr[j] + arr[k]) > target)  k--;
                  else    j++;
              }
          }
          return cnt;
      }
  }
