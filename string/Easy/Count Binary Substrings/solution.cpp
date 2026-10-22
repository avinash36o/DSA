class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size(), i=0, prev=0, curr=0, ans=0;
        //build prev
        while(i<n && s[i]==s[0]){
            prev++; i++;
        }
        //build curr
        while(i<n){
            int x=s[i];
            while(i<n && s[i]==x){
                curr++;
                i++;
            }
            ans+=min(prev,curr);
            prev=curr; curr=0;
        }
        return ans;
    }
};