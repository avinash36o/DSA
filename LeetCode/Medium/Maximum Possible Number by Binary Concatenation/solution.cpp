class Solution {
public:
    int binaryToNum(string s) {
        int n = s.size(), factor = 1, ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            ans += factor * (s[i] - '0');
            factor *= 2;
        }

        return ans;
    }

    int deciTobin(int n) {
        int ans = 0, power = 1;

        while (n > 0) {
            int rem = n % 2;
            n /= 2;

            ans += rem * power;
            power *= 10;
        }

        return ans;
    }

    int maxGoodNumber(vector<int>& nums) {
        vector<string> bin;

        // Convert decimal numbers to binary strings
        for (int n : nums) {
            bin.push_back(to_string(deciTobin(n)));
        }

        // Arrange binary strings to get maximum concatenation
        sort(bin.begin(), bin.end(), [](string a, string b) {
            return a + b > b + a;
        });

        // Concatenate
        string s = "";
        for (string x : bin) {
            s += x;
        }

        // Convert final binary string to decimal
        return binaryToNum(s);
    }
};