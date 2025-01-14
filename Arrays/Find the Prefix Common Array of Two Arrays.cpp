
    Problem Link : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2025-01-14

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> arr(n+1, 0), ans(n);

        int cnt = 0;
        for(int i=0; i<n; i++){

            arr[A[i]]++;
            if(arr[A[i]] == 2)  cnt++;

            arr[B[i]]++;
            if(arr[B[i]] == 2)  cnt++;

            ans[i] = cnt;
        }
        return ans;
    }
};
