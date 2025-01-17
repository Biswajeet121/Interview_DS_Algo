
    Problem Link : https://leetcode.com/problems/neighboring-bitwise-xor/description/?envType=daily-question&envId=2025-01-17

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int Xor = 0;
        for(int i=0; i<n; i++){
            Xor ^= derived[i];
        }
        if(Xor == 0)return true;
        return false;
    }
};
