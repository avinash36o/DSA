class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int length = strs[0].size();

        for(int i = 1; i < strs.size(); i++) {
            int currLength = 0;
            int j = 0;

            while(j < strs[i-1].size() &&
                  j < strs[i].size() &&
                  strs[i-1][j] == strs[i][j]) {
                currLength++;
                j++;
            }

            length = min(length, currLength);
        }

        return strs[0].substr(0, length);
    }
};