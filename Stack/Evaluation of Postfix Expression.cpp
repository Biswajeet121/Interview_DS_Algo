
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/evaluation-of-postfix-expression1735

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(arr[i] == "+" || arr[i] == "-" || arr[i] == "*" || arr[i] == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int ans = 0;
                switch(arr[i][0]){
                    case '+':
                        ans = (a + b);
                        break;
                    case '-':
                        ans = (a - b);
                        break;
                    case '*':
                        ans = (a * b);
                        break;
                    case '/':
                        ans = (a / b);
                        break;
                }
                st.push(ans);
            }
            else{
                st.push(stoi(arr[i]));
            }
        }
        return st.top();
    }
};
