# Number of Substrings Containing All Three Characters

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 15, 2026 |
| **Tags** | Hash Table, String, Sliding Window |
| **Link** | [View Problem](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/) |
| **Runtime** | 2539 ms |
| **Memory** | 11.1 MB |

## Approach

for each window check if (a,b,c) present. if yes then add this to answer and also check for the st++. if no then increase the size of the window by end++;

## Problem Description

<p>Given a string <code>s</code>&nbsp;consisting only of characters <em>a</em>, <em>b</em> and <em>c</em>.</p>

<p>Return the number of substrings containing <b>at least</b>&nbsp;one occurrence of all these characters <em>a</em>, <em>b</em> and <em>c</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abcabc"
<strong>Output:</strong> 10
<strong>Explanation:</strong> The substrings containing&nbsp;at least&nbsp;one occurrence of the characters&nbsp;<em>a</em>,&nbsp;<em>b</em>&nbsp;and&nbsp;<em>c are "</em>abc<em>", "</em>abca<em>", "</em>abcab<em>", "</em>abcabc<em>", "</em>bca<em>", "</em>bcab<em>", "</em>bcabc<em>", "</em>cab<em>", "</em>cabc<em>" </em>and<em> "</em>abc<em>" </em>(<strong>again</strong>)<em>. </em>
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aaacb"
<strong>Output:</strong> 3
<strong>Explanation:</strong> The substrings containing&nbsp;at least&nbsp;one occurrence of the characters&nbsp;<em>a</em>,&nbsp;<em>b</em>&nbsp;and&nbsp;<em>c are "</em>aaacb<em>", "</em>aacb<em>" </em>and<em> "</em>acb<em>".</em><em> </em>
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "abc"
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= s.length &lt;= 5 x 10<sup>4</sup></code></li>
	<li><code>s</code>&nbsp;only consists of <code>'a'</code>, <code>'b'</code> or <code>'c'</code> characters.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅Explained w/ Images🏆Made Easy🔥C++
**Author**: [@Manohar_001](https://leetcode.com/Manohar_001/)
**Upvotes**: 381 👍
**Link**: [View Original Post](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/solutions/3459766/)

---

# \uD83D\uDE09Don\'t just watch & move away, also give an Upvote.\uD83D\uDE09

###### I\'ve used acronym ***wind.*** for ***window***.
###### And acronym ***substr.*** for ***substring***.

![leetcode 1358_1.jpg](https://assets.leetcode.com/users/images/343f8496-0610-4bda-9e65-c97a6fb7b458_1682576897.4123032.jpeg)

![leetcode 1358_2.jpg](https://assets.leetcode.com/users/images/865e5f8f-6a1f-4186-a73a-d36f1b976bd5_1682576922.321084.jpeg)


# Complexity
- Time complexity: $$O(n)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $$O(27)$$ `for hash`
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
# \uD83D\uDE09Please upvote it motivates me\uD83D\uDE09
# Code
```
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = size(s);

        int i=0,j=0,count=0;

        unordered_map<char, int> mp;

        while(j<n)
        {
            mp[s[j]]++;

            while(mp[\'a\']>=1 && mp[\'b\']>=1 && mp[\'c\']>=1)
            {
                count += (n - j);

                //shrinking the window
                mp[s[i]]--;
                i++;
            }
            j++;
        }


<!-- \u2705Well before returning "count" don\'t forget to UPVOTE.\u2705 -->
        return count;
    }
};
```
### If there\'s any doubt please feel free to comment.
![Leetcode Upvote.gif](https://assets.leetcode.com/users/images/0f5cb7f7-08ee-47c0-aade-b01fc4bc644a_1682580196.8159347.gif)


</details>
