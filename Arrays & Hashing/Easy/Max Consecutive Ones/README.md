# Max Consecutive Ones

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | October 4, 2026 |
| **Tags** | Array |
| **Link** | [View Problem](https://leetcode.com/problems/max-consecutive-ones/) |
| **Runtime** | 0 ms |
| **Memory** | 50.3 MB |

## Approach

each time we are getting 1 increase the currCount. if  0 then make currCount=0

## Problem Description

<p>Given a binary array <code>nums</code>, return <em>the maximum number of consecutive </em><code>1</code><em>'s in the array</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,0,1,1,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,0,1,1,0,1]
<strong>Output:</strong> 2
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Max Consecutive Ones Solution in C++
**Author**: [@The_Kunal_Singh](https://leetcode.com/The_Kunal_Singh/)
**Upvotes**: 45 👍
**Link**: [View Original Post](https://leetcode.com/problems/max-consecutive-ones/solutions/3453972/)

---

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
O(n)
- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
O(1)
# Code
```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i, count=0, max=0;
        for(i=0 ; i<nums.size() ; i++)
        {
            if(nums[i]==1)
            {
                count++;
                if(count>max)
                {
                    max = count;
                }
            }
            else
            {
                count=0;
            }
        }
        return max;
    }
};
```
![upvote new.jpg](https://assets.leetcode.com/users/images/156f2a0d-f889-4af0-8979-f8d3d96b8ee5_1682612653.9251022.jpeg)


</details>
