# Find All Numbers Disappeared in an Array

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | October 5, 2026 |
| **Tags** | Array, Hash Table |
| **Link** | [View Problem](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) |
| **Runtime** | 4 ms |
| **Memory** | 53 MB |

## Problem Description

<p>Given an array <code>nums</code> of <code>n</code> integers where <code>nums[i]</code> is in the range <code>[1, n]</code>, return <em>an array of all the integers in the range</em> <code>[1, n]</code> <em>that do not appear in</em> <code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [4,3,2,7,8,2,3,1]
<strong>Output:</strong> [5,6]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,1]
<strong>Output:</strong> [2]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= n</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you do it without extra space and in <code>O(n)</code> runtime? You may assume the returned list does not count as extra space.</p>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Easy C++ with explanation. O(N) running time, O(1) space.
**Author**: [@MalJ](https://leetcode.com/MalJ/)
**Upvotes**: 45 👍
**Link**: [View Original Post](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/solutions/419876/)

---

**Algorithm**

We know that all the values are between 1 and the size of the array, so the idea is to use the indices of the original array to represent the values that are found in the array.
We know that all the values in the array are positive, so we can signal the presence of a value by changing its index (or better still, like in my implementation, the index minus 1, to avoid the \'special case\' of values that equal n, which has no vector element) to be negative.
We then loop over the vector, and any positive index indicates that the value (index + 1) does not appear in the vector, so we add it to the list to return.


**Complexity**

We loop over the array twice, so the running time is O(2N), which is O(N).
We use the original vector for keeping count of which values appear in the array, so we use O(1) space.


**The Code**

```
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> results;
        
        // Set contents of all indices (minus 1) that appear in the array to be negative
        for (int i = 0; i < nums.size(); ++i)
        {
			// Note that we have to use the absolute value in the next 2 lines, to avoid trying to access a negative index in some cases
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }
        
        // A positive element means that the element (index + 1) does not appear in the array, so save it
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)
                results.push_back(i + 1);
        
        return results;
    }
};
```

</details>
