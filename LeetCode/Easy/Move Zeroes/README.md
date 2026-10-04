# Move Zeroes

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | October 4, 2026 |
| **Tags** | Array, Two Pointers |
| **Link** | [View Problem](https://leetcode.com/problems/move-zeroes/) |
| **Runtime** | 0 ms |
| **Memory** | 23.7 MB |

## Approach

keep tracking the the leftest zero idx and swap it every time you get some non zero

## Problem Description

<p>Given an integer array <code>nums</code>, move all <code>0</code>'s to the end of it while maintaining the relative order of the non-zero elements.</p>

<p><strong>Note</strong> that you must do this in-place without making a copy of the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [0,1,0,3,12]
<strong>Output:</strong> [1,3,12,0,0]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [0]
<strong>Output:</strong> [0]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you minimize the total number of operations done?

##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: My simple C++ solution
**Author**: [@hyzhang](https://leetcode.com/hyzhang/)
**Upvotes**: 672 👍
**Link**: [View Original Post](https://leetcode.com/problems/move-zeroes/solutions/72005/)

---

    class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int j = 0;
            // move all the nonzero elements advance
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != 0) {
                    nums[j++] = nums[i];
                }
            }
            for (;j < nums.size(); j++) {
                nums[j] = 0;
            }
        }
    };

</details>
