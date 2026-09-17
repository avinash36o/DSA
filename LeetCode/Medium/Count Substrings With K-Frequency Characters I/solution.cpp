class Solution {
public:
    bool isValid(vector<int>&freq, int k){
        for(int x: freq){
            if(x>=k)return true;
        }
        return false;
    }

    int numberOfSubstrings(string s, int k) {
        int n=s.size();
        int st=0,end=0,ans=0;
        vector<int>freq(26,0);   
        freq[s[end]-'a']++;

        while(st<=end && end<n && st<n){
            if(isValid(freq,k)){
                // cout<<"st: "<<st<<" end: "<<end;
                ans+=1+(n-end-1);
                // cout<<" ans: "<<ans<<endl;
                freq[s[st]-'a']--;
                st++;
                if(st>end && st<n && end<n){
                    end++;
                    freq[s[end]-'a']++;
                }
            }else{
                end++;
                if(end<n){
                    freq[s[end]-'a']++;
                }
            }
        }
        return ans;
    }
};