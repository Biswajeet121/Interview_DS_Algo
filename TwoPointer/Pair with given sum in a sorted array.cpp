Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/pair-with-given-sum-in-a-sorted-array4940
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int n = arr.size(), cnt = 0;
        int i=0, j=n-1;
        while(i < j){
            if(arr[i] + arr[j] == target){
                if(arr[i] == arr[j]){
                    cnt += ((j-i+1)*(j-i))/2;
                    i=j;
                }
                else{
                    int cnt1 = 1, cnt2 = 1;
                    while(i<n-1 && arr[i] == arr[i+1]){
                        cnt1++;
                        i++;
                    }
                    while(j>0 && arr[j] == arr[j-1]){
                        cnt2++;
                        j--;
                    }
                    cnt += (cnt1 * cnt2);
                }
                i++;
                j--;
            }
            else if(arr[i] + arr[j] < target)
                i++;
            else
                j--;
        }
        return cnt;
    }
};
