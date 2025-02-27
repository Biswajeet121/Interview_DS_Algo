
    Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/get-minimum-element-from-stack

class Solution {
  public:
    vector<int> minArrIdx;
    vector<int> stackArr;
    int idx;
    Solution() {
        // code here
        idx = 0;
    }
    // Add an element to the top of Stack
    void push(int x) {
        // code here
        stackArr.push_back(x);
        if(minArrIdx.empty() || x < stackArr[minArrIdx.back()])
            minArrIdx.push_back(idx);
        idx++;
    }
    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!stackArr.empty()){
            if(stackArr[minArrIdx.back()] == stackArr.back())
                minArrIdx.pop_back();
            stackArr.pop_back();
            idx--;
        }
    }
    // Returns top element of the Stack
    int peek() {
        // code here
        if(stackArr.empty())    return -1;
        return stackArr.back();
    }
    // Finds minimum element of Stack
    int getMin() {
        // code here
        if(stackArr.empty())    return -1;
        return stackArr[minArrIdx.back()];
    }
};
