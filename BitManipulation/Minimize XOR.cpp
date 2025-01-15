

    Problem Link : https://leetcode.com/problems/minimize-xor/description/?envType=daily-question&envId=2025-01-15

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int count2 = __builtin_popcount(num2);
        int x = 0;
        for (int i = 31; i >= 0; i--) {
            if (count2 == 0) break;
            if (num1 & (1 << i)) {
                x |= (1 << i);
                count2--;
            }
        }
        for (int i = 0; i < 32; i++) {
            if (count2 == 0) break;
            if ((x & (1 << i)) == 0) {
                x |= (1 << i);
                count2--;
            }
        }
        return x;
    }
};
