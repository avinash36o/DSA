class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(128, -1);

        int ans = 0, st = 0;

        for(int end = 0; end < s.size(); end++) {

            if(last[s[end]] >= st) {
                st = last[s[end]] + 1;
            }

            last[s[end]] = end;

            ans = max(ans, end - st + 1);
        }

        return ans;
    }
};