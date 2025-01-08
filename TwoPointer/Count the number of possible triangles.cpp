
Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/count-possible-triangles-1587115620

class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int c = 0;
        for(int high = n - 1; high >= 2; high--){
            int low = 0, i = high -1;
            while(low < i){
                if(arr[low] + arr[i] > arr[high]){
                    c += i-low;
                    i--;
                }
                else{
                    low++;
                }
            }
        }
        return c;
    }
};
