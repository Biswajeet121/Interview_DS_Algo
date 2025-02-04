
    Problem Link : https://leetcode.com/problems/maximum-ascending-subarray-sum/description/?envType=daily-question&envId=2025-02-04

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN, sum = nums[0];

        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]){
                sum += nums[i];
            }
            else{
                maxi = max(maxi, sum);
                sum = nums[i];
            }
        }
        maxi = max(maxi, sum);

        return maxi;
    }
};
