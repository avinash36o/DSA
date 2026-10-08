class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int st = 0;

        for (int end = 0; end <= n; end++) {
            if(end==n || s[end]==' '){
                reverse(s.begin()+st, s.begin()+end);
                st=end+1;
            }
        }
        return s;
    }
};