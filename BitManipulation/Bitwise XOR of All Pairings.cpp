
    Problem Link : https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/?envType=daily-question&envId=2025-01-16

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if(n % 2 == 0 && m % 2 == 0) {
            return 0;
        }
        int ans = 0;
        if(n & 1) {
            for(auto &it : nums2) {
                ans ^= it;
            }
        }
        if(m & 1) {
            for(auto &it : nums1) {
                ans ^= it;
            }
        }
        return ans;
    }
};
