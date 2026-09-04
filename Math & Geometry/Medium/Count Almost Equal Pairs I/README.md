# Count Almost Equal Pairs I

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 4, 2026 |
| **Tags** | Array, Hash Table, Sorting, Counting, Enumeration |
| **Link** | [View Problem](https://leetcode.com/problems/count-almost-equal-pairs-i/) |
| **Runtime** | 970 ms |
| **Memory** | 342.7 MB |

## Approach

if the diff is less than 2 and freq of each char is same then it will be consider in ans

## Problem Description

<p>You are given an array <code>nums</code> consisting of positive integers.</p>

<p>We call two integers <code>x</code> and <code>y</code> in this problem <strong>almost equal</strong> if both integers can become equal after performing the following operation <strong>at most once</strong>:</p>

<ul>
	<li>Choose <strong>either</strong> <code>x</code> or <code>y</code> and swap any two digits within the chosen number.</li>
</ul>

<p>Return the number of indices <code>i</code> and <code>j</code> in <code>nums</code> where <code>i &lt; j</code> such that <code>nums[i]</code> and <code>nums[j]</code> are <strong>almost equal</strong>.</p>

<p><strong>Note</strong> that it is allowed for an integer to have leading zeros after performing an operation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [3,12,30,17,21]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>The almost equal pairs of elements are:</p>

<ul>
	<li>3 and 30. By swapping 3 and 0 in 30, you get 3.</li>
	<li>12 and 21. By swapping 1 and 2 in 12, you get 21.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,1,1,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">10</span></p>

<p><strong>Explanation:</strong></p>

<p>Every two elements in the array are almost equal.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [123,231]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>We cannot swap any two digits of 123 or 231 to reach the other.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Easy to understand C++ Solution
**Author**: [@rajvir_singh](https://leetcode.com/rajvir_singh/)
**Upvotes**: 34 👍
**Link**: [View Original Post](https://leetcode.com/problems/count-almost-equal-pairs-i/solutions/5686683/)

---

# Complexity
- Time complexity: O(n^2)

- Space complexity: O(1)

# Code
```cpp []
class Solution {
private:
    bool almostEqual(int x, int y){
        string s1 = to_string(x), s2 = to_string(y);
        int n = s1.length(), m = s2.length();
        int maxLen = max(n, m);
        // make the lengths of 2 strings equal by adding zeros to the front
        while(n != maxLen){
            s1 = "0" + s1; n++;
        }
        while(m != maxLen){
            s2 = "0" + s2; m++;
        }
        int diff = 0;
        unordered_map<char,int> mp1, mp2;
        for(int i = 0; i < n; i++){
            diff += (s1[i] != s2[i]);
            mp1[s1[i]]++; mp2[s2[i]]++;
        }
        return diff <= 2 && mp1 == mp2;
    }
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                count += almostEqual(nums[i], nums[j]);
            }
        }
        return count;
    }
};
```

</details>
