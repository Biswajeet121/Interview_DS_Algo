
    Problem Link : https://www.geeksforgeeks.org/problems/decode-the-string2444/1

class Solution {
  public:
    string decodedString(string &s) {
        // code here
        int n = s.size();
        string num = "", str = "";
        stack<string> st;
        
        for(int i=0; i<n; i++){
            if(s[i]>='0' && s[i]<='9')  num += s[i];
            else if(s[i]>='a' && s[i]<='z') str += s[i];
            else if(s[i] == '['){
                if(!str.empty())    st.push(str);
                st.push(num);   st.push("[");
                str = "";   num = "";
            }
            else{
                if(!str.empty()){
                    st.push(str);
                    str = "";
                }
                string s = st.top();   st.pop();
                if(st.top() == "["){
                    st.pop();
                    int itr = stoi(st.top());   st.pop();
                    string ch = "";
                    for(int i=0; i<itr; i++){
                        ch += s;
                    }
                    if(!st.empty() && st.top() != "[")  st.top() += ch;
                    else   st.push(ch);
                }
                else{
                    string ch = st.top();
                    if(ch[0] == '[' || (ch[0] >='0' && ch[0] <= '9'))   st.pop();
                    else{
                        st.top() += s;
                        i--;
                    }
                }
            }
        }
        return st.top();
    }
};
