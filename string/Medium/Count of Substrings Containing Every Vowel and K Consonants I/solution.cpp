class Solution {
public:

        int countOfSubstrings(string word, int k) {
        int n = word.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> vowel;
            int consonant = 0;
            for (int j = i; j < n; j++) {
                if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' ||
                    word[j] == 'o' || word[j] == 'u') 
                {
                    vowel[word[j]]++;
                } else {
                    consonant++;
                }
                if (vowel['a'] >= 1 && vowel['e'] >= 1 && vowel['i'] >= 1 && vowel['o'] >= 1 && vowel['u'] >= 1 && consonant==k) {
                    ans++;
                }
                if(consonant>k)break;
            }
        }
        return ans;
    }
};