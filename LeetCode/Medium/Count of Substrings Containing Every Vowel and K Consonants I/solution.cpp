class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long countAtLeast(string& word, int k) {
        int n = word.size();
        unordered_map<char, int> vowel;
        int cons = 0, st = 0;
        long long ans = 0;

        for (int end = 0; end < n; end++) {
            if (isVowel(word[end])) {
                vowel[word[end]]++;
            } else {
                cons++;
            }

            // Shrink window while it contains all 5 vowels and at least k consonants
            while (vowel.size() == 5 && cons >= k) {
                // All substrings from 'end' to 'n-1' starting at 'st' are valid
                ans += (n - end);

                if (isVowel(word[st])) {
                    vowel[word[st]]--;
                    if (vowel[word[st]] == 0) {
                        vowel.erase(word[st]);
                    }
                } else {
                    cons--;
                }
                st++;
            }
        }
        return ans;
    }

public:
    long long countOfSubstrings(string word, int k) {
        return countAtLeast(word, k) - countAtLeast(word, k + 1);
    }
};