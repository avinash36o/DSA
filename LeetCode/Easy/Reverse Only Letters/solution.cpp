class Solution {
public:
    bool isValid(char c){
        if((c>='a'&& c<='z') || (c>='A' && c<='Z'))return true;
        return false;
    }

    string reverseOnlyLetters(string s) {
        int st=0, end=s.size()-1;
        while(st<=end){
            if(!isValid(s[st])){
                st++; continue;
            }
            if(!isValid(s[end])){
                end--; continue;
            }
            swap(s[st], s[end]);
            st++;end--;
        }
        return s;
    }
};