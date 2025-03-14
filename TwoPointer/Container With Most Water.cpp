/*

    Problem Link : https://leetcode.com/problems/container-with-most-water/description/
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/two-pointer-technique-gfg-160/problem/container-with-most-water0535
    
    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
    Find two lines that together with the x-axis form a container, such that the container contains the most water.
    Return the maximum amount of water a container can store.
    Notice that you may not slant the container.
    
    Example 1:
    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n - 1;
        int maxi = INT_MIN;
        while(i < j){
            int mini = min(height[i], height[j]);
            int area = mini * (j - i);
            maxi = max(maxi, area);
            if(height[i] == height[j]){
                i++;
                j--;
            }
            else if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxi;
    }
};
