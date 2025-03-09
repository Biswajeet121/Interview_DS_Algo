
  Problem Link : https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/count-palindrome-sub-strings-of-a-string0652

class Solution {
  public:
    int countPS(string &s) {
        int n=s.length();
        int res=0;
        
        //odd palindrome strings
        for(int i=0;i<n;i++){
            int l=i,r=i;
            
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>=2)
                res++;
                
                l--;
                r++;
            }
            
            //even length palindromes
             l=i,r=i+1;
            
            while(l>=0 && r<n && s[l]==s[r]){
                if(r-l+1>=2)
                res++;
                
                l--;
                r++;
            }
        }
        
        return res;
        
    }
};
