class Solution {
public:
    int maxOperations(string s) {
        int n=s.size(), ans=0;
        int countZero=!(s[n-1]-'0');

        for(int i=n-2; i>=0; i--){
            if(s[i]=='0' && s[i+1]=='1'){
                countZero++;
            }

            if(s[i]=='1'){
                ans+=countZero;
            }
        }
        return ans;
    }
};