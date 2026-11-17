class Solution {
public:
    string minWindow(string s, string t) {
        int n=t.size(), m=s.size(), windowSize=INT_MAX;
        unordered_map<char,int>tFreq;
        unordered_map<char,int>sFreq;

        for(int i=0; i<n; i++){
            tFreq[t[i]]++;
        }
        int required=tFreq.size();
        int formed=0;
        int st=0, minSt=0;

        for(int end=0; end<m; end++){
            sFreq[s[end]]++;
            if(tFreq.count(s[end]) && sFreq[s[end]]==tFreq[s[end]]){
                formed++;
            }
            while(required==formed){
                if(end-st+1<windowSize){
                    windowSize=end-st+1;
                    minSt=st;
                }
                sFreq[s[st]]--;
                if(tFreq.count(s[st]) && sFreq[s[st]]<tFreq[s[st]]){
                    formed--;
                }
                st++;
            }
        }
        return windowSize==INT_MAX ? "" : s.substr(minSt, windowSize);
    }
};