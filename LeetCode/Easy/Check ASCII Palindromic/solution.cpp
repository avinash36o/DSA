class Solution {
public:
    bool isPal(string s){
        int st=0, end=s.size()-1;

        while(st<=end){
            if(s[st] != s[end]){
                return false;
            }
            st++;end--;
        }
        return true;
    }
    
    bool isPalindromic(string s) {
        string str="";

        for(int i=0; i<s.size(); i++){
            int curr=(int)s[i];
            string binary=bitset<8>(curr).to_string();
            str+=binary;
        }
        return isPal(str);
    }
};