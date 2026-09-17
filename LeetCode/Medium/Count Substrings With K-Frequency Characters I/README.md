# Count Substrings With K-Frequency Characters I

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 17, 2026 |
| **Tags** | Hash Table, String, Sliding Window |
| **Link** | [View Problem](https://leetcode.com/problems/count-substrings-with-k-frequency-characters-i/) |
| **Runtime** | 0 ms |
| **Memory** | 10 MB |

## Approach

if a window is valid, add in ans and st++ and again check for validity. else end++; be caution of the out of bound

## Problem Description

<p>Given a string <code>s</code> and an integer <code>k</code>, return the total number of <span data-keyword="substring-nonempty" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_t_" data-state="closed" class="">substrings</button></span> of <code>s</code> where <strong>at least one</strong> character appears <strong>at least</strong> <code>k</code> times.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "abacb", k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>The valid substrings are:</p>

<ul>
	<li><code>"aba"</code> (character <code>'a'</code> appears 2 times).</li>
	<li><code>"abac"</code> (character <code>'a'</code> appears 2 times).</li>
	<li><code>"abacb"</code> (character <code>'a'</code> appears 2 times).</li>
	<li><code>"bacb"</code> (character <code>'b'</code> appears 2 times).</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "abcde", k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">15</span></p>

<p><strong>Explanation:</strong></p>

<p>All substrings are valid because every character appears at least once.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3000</code></li>
	<li><code>1 &lt;= k &lt;= s.length</code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Easiest Solution 🔥✅ | Sliding Window | BEATS 94.94%
**Author**: [@1AFN19tfV2](https://leetcode.com/1AFN19tfV2/)
**Upvotes**: 25 👍
**Link**: [View Original Post](https://leetcode.com/problems/count-substrings-with-k-frequency-characters-i/solutions/5939809/)

---

# Intuition
We need to count substrings where at least one character appears exactly `k` times. A sliding window approach helps us track character frequencies and adjust the window to find valid substrings efficiently.

# Approach
1. Use a sliding window with a pointer `l` and a frequency map `d` to track characters in the window.
2. For each character, update its frequency in `d`.
3. If any character\'s frequency reaches `k`, shrink the window by incrementing `l`.
4. Add the number of valid starting positions (`l`) to the result for each window.
5. Return the total count of valid substrings.

# Complexity
- Time complexity: $$O(n)$$, where n is the length of the string.

- Space complexity: $$O(1)$$, since the maximum number of items we store in our hashmap is 26 (every letter).

# Code
```python3 []
class Solution:
    def numberOfSubstrings(self, s: str, k: int) -> int:
        ans = 0
        l = 0
        d = {}
        for c in s:
            d[c] = d.get(c, 0) + 1
            while d[c] == k:
                d[s[l]] -= 1
                l += 1
            ans += l
        return ans
```
```cpp []
class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int ans = 0;
        int l = 0;
        unordered_map<char, int> d;
        
        for (char c : s) {
            d[c]++;
            while (d[c] == k) {
                d[s[l]]--;
                l++;
            }
            ans += l;
        }
        
        return ans;
    }
};
```
```java []
import java.util.HashMap;

class Solution {
    public int numberOfSubstrings(String s, int k) {
        int ans = 0;
        int l = 0;
        HashMap<Character, Integer> d = new HashMap<>();
        
        for (char c : s.toCharArray()) {
            d.put(c, d.getOrDefault(c, 0) + 1);
            
            while (d.get(c) == k) {
                d.put(s.charAt(l), d.get(s.charAt(l)) - 1);
                l++;
            }
            
            ans += l;
        }

        return ans;
    }
}
```
![image.png](https://assets.leetcode.com/users/images/0e072e9b-4678-4507-8b78-beefacf5cba8_1729700815.6733763.png)


</details>
