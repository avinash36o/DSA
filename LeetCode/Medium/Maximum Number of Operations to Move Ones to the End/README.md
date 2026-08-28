# Maximum Number of Operations to Move Ones to the End

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | August 28, 2026 |
| **Tags** | String, Greedy, Counting |
| **Link** | [View Problem](https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/) |
| **Runtime** | 12 ms |
| **Memory** | 15.7 MB |

## Approach

count the gaps after the curr idx. gap is the max time 1's can move. add all the moves.

## Problem Description

<p>You are given a <span data-keyword="binary-string" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_t_" data-state="closed" class="">binary string</button></span> <code>s</code>.</p>

<p>You can perform the following operation on the string <strong>any</strong> number of times:</p>

<ul>
	<li>Choose <strong>any</strong> index <code>i</code> from the string where <code>i + 1 &lt; s.length</code> such that <code>s[i] == '1'</code> and <code>s[i + 1] == '0'</code>.</li>
	<li>Move the character <code>s[i]</code> to the <strong>right</strong> until it reaches the end of the string or another <code>'1'</code>. For example, for <code>s = "010010"</code>, if we choose <code>i = 1</code>, the resulting string will be <code>s = "0<strong><u>001</u></strong>10"</code>.</li>
</ul>

<p>Return the <strong>maximum</strong> number of operations that you can perform.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "1001101"</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>We can perform the following operations:</p>

<ul>
	<li>Choose index <code>i = 0</code>. The resulting string is <code>s = "<u><strong>001</strong></u>1101"</code>.</li>
	<li>Choose index <code>i = 4</code>. The resulting string is <code>s = "0011<u><strong>01</strong></u>1"</code>.</li>
	<li>Choose index <code>i = 3</code>. The resulting string is <code>s = "001<strong><u>01</u></strong>11"</code>.</li>
	<li>Choose index <code>i = 2</code>. The resulting string is <code>s = "00<strong><u>01</u></strong>111"</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "00111"</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Greedy
**Author**: [@fahad84](https://leetcode.com/fahad84/)
**Upvotes**: 42 👍
**Link**: [View Original Post](https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/solutions/5508962/)

---

# Approach
1. A **\'1\'** in the string can only move if it is immediately followed by a **\'0\'**. When a **\'1\'** moves, it continues to shift right until it encounters another **\'1\'** or reaches the end of the string.
3. To determine the maximum number of operations, follow these steps:

```
- Track how many \'1\'s are to the left of each \'0\'. 
- Each \'0\' encountered allows all previously counted \'1\'s to move past it.

- For every \'0\', add the number of \'1\'s encountered so far to a running total. 
- This accounts for all possible moves that can be performed for each \'0\'.
```

3. In the code, this is achieved by:


- Iterating through the string while maintaining a count of **\'1\'s** (cnt).
- Whenever a **\'0\'** is encountered, adding the current count of **\'1\'s** to the total number of operations (ans).
- **Skipping** over consecutive **\'0\'s** until the next **\'1\'** is found or the end of the string is reached.

# Complexity
- Time complexity: $$O(n)$$

- Space complexity: $$O(1)$$

# Code
```C++ []
class Solution {
public:
    int maxOperations(string s) {
        int n = s.length(), cnt = 0, ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == \'0\'){
                ans += cnt;
                while(i < n && s[i] != \'1\'){
                    i++;
                }
            }
            cnt++;
        }
        return ans;
    }
};
```
```Java []
class Solution {
    public int maxOperations(String s) {
        int n = s.length(), cnt = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == \'0\') {
                ans += cnt;
                while (i < n && s.charAt(i) != \'1\') {
                    i++;
                }
            }
            cnt++;
        }
        return ans;
    }
}

```
```Python3 []
class Solution:
    def maxOperations(self, s: str) -> int:
        n = len(s)
        cnt = 0
        ans = 0
        i = 0
        while i < n:
            if s[i] == \'0\':
                ans += cnt
                while i < n and s[i] != \'1\':
                    i += 1
            cnt += 1
            i += 1
        return ans

```

# Alternate Loop
```
for(int i = 0; i < n; i++){
    if(s[i] == \'1\') cnt++;
    else{
        while(i < n && s[i] != \'1\'){
            i++;
        }
        res += cnt;
        cnt++; // since s[i] = 1 after the while loop if (i < n) 
    }
}
```


</details>
