class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0, st = 0;
        unordered_map<char, int> freq; // char and its freq

        for (int end = 0; end < n; end++) {
            freq[s[end]]++;
            if (freq[s[end]] <= 1) {
                ans = max(ans, end - st + 1);
            } else {
                while (freq[s[end]] > 1) {
                    freq[s[st]]--;
                    st++;
                }
            }
        }
        return ans;
    }
};