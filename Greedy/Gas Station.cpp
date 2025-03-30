
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/greedy-gfg-160/problem/circular-tour-1587115620

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n = gas.size();
        int totalGas = 0, totalCost = 0;
        for(int i=0; i<n; i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if(totalCost > totalGas)
            return -1;
        
        int idx = -1;
        totalGas = 0;
        for(int i=0; i<n; i++){
            totalGas += (gas[i] - cost[i]);
            if(totalGas < 0){
                idx = -1;
                totalGas = 0;
            }
            else{
                if(idx == -1)
                    idx = i;
            }
        }
        return idx;
    }
};
