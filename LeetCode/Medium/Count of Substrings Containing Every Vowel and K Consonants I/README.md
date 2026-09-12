# Count of Substrings Containing Every Vowel and K Consonants I

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 12, 2026 |
| **Tags** | Hash Table, String, Sliding Window |
| **Link** | [View Problem](https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/) |
| **Runtime** | 4 ms |
| **Memory** | 10.3 MB |

## Approach

count n(substring containing atleast k consonant and all vowel) and n(substring containing atleast k +1 consonant and all vowel ). then substarct them



## Problem Description

<p>You are given a string <code>word</code> and a <strong>non-negative</strong> integer <code>k</code>.</p>

<p>Return the total number of <span data-keyword="substring-nonempty" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_bm_" data-state="closed" class="">substrings</button></span> of <code>word</code> that contain every vowel (<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, and <code>'u'</code>) <strong>at least</strong> once and <strong>exactly</strong> <code>k</code> consonants.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = "aeioqq", k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>There is no substring with every vowel.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = "aeiou", k = 0</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The only substring with every vowel and zero consonants is <code>word[0..4]</code>, which is <code>"aeiou"</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">word = "</span>ieaouqqieaouqq<span class="example-io">", k = 1</span></p>

<p><strong>Output:</strong> 3</p>

<p><strong>Explanation:</strong></p>

<p>The substrings with every vowel and one consonant are:</p>

<ul>
	<li><code>word[0..5]</code>, which is <code>"ieaouq"</code>.</li>
	<li><code>word[6..11]</code>, which is <code>"qieaou"</code>.</li>
	<li><code>word[7..12]</code>, which is <code>"ieaouq"</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>5 &lt;= word.length &lt;= 250</code></li>
	<li><code>word</code> consists only of lowercase English letters.</li>
	<li><code>0 &lt;= k &lt;= word.length - 5</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Simple Brute Force
**Author**: [@_sxrthakk](https://leetcode.com/_sxrthakk/)
**Upvotes**: 21 👍
**Link**: [View Original Post](https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/solutions/5846122/)

---

# Approach
1. **Initialization of Variables :**
- ans: This variable is initialized to zero and will hold the count of valid substrings that meet the criteria specified.
- The outer loop iterates through each character of the string s, setting up the starting point of a substring at index i.
2. **Outer Loop (i) :**
- This loop runs from 0 to s.size() - 1. Each iteration represents a new starting point for the substring.
- At the beginning of each iteration, we reset the vowel counters (a, e, m, o, u) and the consonant counter (c) to zero.
3. **Inner Loop (j) :**
- The inner loop starts at the current index i and extends to the end of the string, thus examining all possible substrings that begin with the character at index i.
- Each iteration of this inner loop examines the character at index j.

4. **Character Classification :**
- The inner loop contains a series of conditional statements that check the current character s[j]:
- If s[j] is a vowel (\'a\', \'e\', \'i\', \'o\', or \'u\'), the corresponding counter (a, e, m, o, or u) is incremented.
- If s[j] is not a vowel (i.e., it is a consonant), the consonant counter (c) is incremented.

5. **Condition Check :**
- After updating the counters for each character added to the current substring, the code checks whether all five vowel counters (a, e, m, o, u) are greater than 0 (indicating that each vowel has been encountered at least once).
- It also checks if the consonant counter (c) is equal to k.
- If both conditions are satisfied, it increments the ans counter by 1, indicating that a valid substring has been found.

6. **Completing the Process :**
- The outer loop continues, and for each starting point i, the inner loop explores all possible substrings starting from that point.
- By the time both loops finish executing, ans contains the total count of valid substrings.

7. **Return Statement :**
- Finally, the function returns the value of ans, which represents the number of substrings that meet the specified criteria.

# Code
```cpp []
int countOfSubstrings(string s, int k) {
    int ans = 0;

    for(int i=0;i<s.size();i++){
        int a=0, e=0, m=0, o=0,u=0,c=0; 
        for(int j=i;j<s.size();j++){
            if(s[j]==\'a\') a++;
            else if(s[j]==\'e\') e++;
            else if(s[j]==\'i\') m++;
            else if(s[j]==\'o\') o++;
            else if(s[j]==\'u\') u++;
            else c++;  

            if(a and e and m and o and u and c==k) ans++;
        }
    }
        
    return ans;
}
```

```Python []
def countOfSubstrings(self,s, k):
    ans = 0
    n = len(s)

    for i in range(n):
        a = e = i_count = o = u = c = 0
        
        for j in range(i, n):
            if s[j] == \'a\':
                a += 1
            elif s[j] == \'e\':
                e += 1
            elif s[j] == \'i\':
                i_count += 1
            elif s[j] == \'o\':
                o += 1
            elif s[j] == \'u\':
                u += 1
            else:
                c += 1
                
                
            if a > 0 and e > 0 and i_count > 0 and o > 0 and u > 0 and c == k:
                ans += 1

    return ans    
```

```Java []
public static int countOfSubstrings(String s, int k) {
        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int a = 0, e = 0, i_count = 0, o = 0, u = 0, c = 0;

            for (int j = i; j < n; j++) {
                if (s.charAt(j) == \'a\') a++;
                else if (s.charAt(j) == \'e\') e++;
                else if (s.charAt(j) == \'i\') i_count++;
                else if (s.charAt(j) == \'o\') o++;
                else if (s.charAt(j) == \'u\') u++;
                else c++;

                if (a > 0 && e > 0 && i_count > 0 && o > 0 && u > 0 && c == k) {
                    ans++;
                }
            }
        }

        return ans;
    }
```



</details>
