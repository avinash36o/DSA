class Solution {
public:
    bool isAllPresent(unordered_map<char, int>& m, string& s) {
        return m[s[0]] >= 1 && m[s[1]] >= 1 && m[s[2]] >= 1;
    }

    int numberOfSubstrings(string s1) {
        string s2="abc";
        unordered_map<char, int> m;
        int st = 0, end = 2, ans = 0, n = s1.size();

        for (int i = 0; i < 3; i++) {
            m[s1[i]]++;
        }

        while (st <= end && end < n) {
            // if window size is less than 3
            if (end - st + 1 < 3) {
                end++;
                m[s1[end]]++;
            }
            // if saare char present hai
            else if (isAllPresent(m, s2)) {
                cout << "st: " << st << " " << "end: " << end << endl;
                ans += 1 + (n - (end + 1));
                m[s1[st]]--;
                st++;
            } else { // agar saare nhi mile
                end++;
                m[s1[end]]++;
            }
        }
        return ans;
    }
};