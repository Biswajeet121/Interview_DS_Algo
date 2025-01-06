/*

    Problem Link : https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/?envType=daily-question&envId=2025-01-06

    You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.
    In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.
    Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.
    Each answer[i] is calculated considering the initial state of the boxes.
    
    Example 1:
    
    Input: boxes = "110"
    Output: [1,1,3]
    Explanation: The answer for each box is as follows:
    1) First box: you will have to move one ball from the second box to the first box in one operation.
    2) Second box: you will have to move one ball from the first box to the second box in one operation.
    3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.

*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int rightOne = 0, leftOne = 0;
        int rightDis = 0, leftDis = 0;
        for(int i=0; i<n; i++){
            if(boxes[i] == '1'){
                rightOne++;
                rightDis += i;
            }
        }
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++){
            ans[i] = rightDis + leftDis;
            if(boxes[i] == '1'){
                leftOne++;
                rightOne--;
            }
            rightDis -= rightOne;
            leftDis += leftOne;
        }
        return ans;
    }
};
