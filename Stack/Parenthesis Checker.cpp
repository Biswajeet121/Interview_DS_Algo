
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/stack-gfg-160/problem/parenthesis-checker2744

class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        int n = s.size();
        stack<char> st;
        for(int i=0; i<n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(
                    (s[i] == ')' && st.top() != '(') ||
                    (s[i] == '}' && st.top() != '{') ||
                    (s[i] == ']' && st.top() != '[')
                ){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};
