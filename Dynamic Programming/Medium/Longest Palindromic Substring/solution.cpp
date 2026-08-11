class Solution {
public:
    string longestPalindrome(string s) {
        string res="";

        for(int i=0; i<s.size(); i++){
            int st=i, end=i; //for odd center
            while(st>=0 && end<s.size() && s[st]==s[end] ){
                st--;
                end++;
            }
            string currStr=s.substr(st+1, end-st-1);
            if(currStr.size()>res.size()) res=currStr;

            st=i, end=i+1; //for even center
            while(st>=0 && end<s.size() && s[st]==s[end] ){
                st--;
                end++;
            }
            currStr=s.substr(st+1, end-st-1);
            if(currStr.size()>res.size()) res=currStr;
        }
        return res;
    }
};