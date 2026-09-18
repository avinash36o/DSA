# Adjacent Increasing Subarrays Detection II

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 18, 2026 |
| **Tags** | Array, Binary Search |
| **Link** | [View Problem](https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/) |
| **Runtime** | 219 ms |
| **Memory** | 173.6 MB |

## Approach

make 2 block each time and get max({ans, b1/2, b2/2, min(b1,b2)});

## Problem Description

<p>Given an array <code>nums</code> of <code>n</code> integers, your task is to find the <strong>maximum</strong> value of <code>k</code> for which there exist <strong>two</strong> adjacent <span data-keyword="subarray-nonempty" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_t_" data-state="closed" class="">subarrays</button></span> of length <code>k</code> each, such that both subarrays are <strong>strictly</strong> <strong>increasing</strong>. Specifically, check if there are <strong>two</strong> subarrays of length <code>k</code> starting at indices <code>a</code> and <code>b</code> (<code>a &lt; b</code>), where:</p>

<ul>
	<li>Both subarrays <code>nums[a..a + k - 1]</code> and <code>nums[b..b + k - 1]</code> are <strong>strictly increasing</strong>.</li>
	<li>The subarrays must be <strong>adjacent</strong>, meaning <code>b = a + k</code>.</li>
</ul>

<p>Return the <strong>maximum</strong> <em>possible</em> value of <code>k</code>.</p>

<p>A <strong>subarray</strong> is a contiguous <b>non-empty</b> sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,5,7,8,9,2,3,4,3,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The subarray starting at index 2 is <code>[7, 8, 9]</code>, which is strictly increasing.</li>
	<li>The subarray starting at index 5 is <code>[2, 3, 4]</code>, which is also strictly increasing.</li>
	<li>These two subarrays are adjacent, and 3 is the <strong>maximum</strong> possible value of <code>k</code> for which two such adjacent strictly increasing subarrays exist.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3,4,4,4,4,5,6,7]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The subarray starting at index 0 is <code>[1, 2]</code>, which is strictly increasing.</li>
	<li>The subarray starting at index 2 is <code>[3, 4]</code>, which is also strictly increasing.</li>
	<li>These two subarrays are adjacent, and 2 is the <strong>maximum</strong> possible value of <code>k</code> for which two such adjacent strictly increasing subarrays exist.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: 100% OPTIMAL SOLUTION | INTUITIVE APPROACH TO MAX  INCREASING SUBARRAYS WITH DETAILED EXPLAINATION.
**Author**: [@agam2271](https://leetcode.com/agam2271/)
**Upvotes**: 16 👍
**Link**: [View Original Post](https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/solutions/6029305/)

---

# Intuition
- To solve this problem, we need to identify consecutive subarrays in the list nums that are strictly increasing. We can keep track of the lengths of these subarrays and update a maximum result based on specific criteria, such as dividing the current length by 2 or taking the minimum of consecutive increasing subarray lengths.

- The key is:
   - If an element continues the increasing sequence, extend the current subarray.
If not, reset the subarray length and keep track of the previous subarray length to evaluate the maximum possible result.


# Approach
Initialize Variables:
**prev**: Tracks the length of the previous increasing subarray.
**curr**: Tracks the length of the current increasing subarray.
ans: Stores the maximum result found so far.
Traverse the Array:

  - For each element starting from the second position:
If nums[i] > nums[i-1]:
Increment curr as it continues the increasing trend.
Else:
The sequence broke, so update prev to curr and reset curr to 1 (new subarray).
Update ans by taking the maximum of ans and the expression max(curr / 2, min(prev, curr)), where curr / 2 or min(prev, curr) evaluates possible maximum lengths based on the problem\u2019s criteria.
Return the Result:

- Return the value of ans, which now contains the length of the longest qualifying subarray.
# Complexity
- Time complexity: **O(n)**, where n is the number of elements in nums. This is because we only pass through the list once.
- Space complexity:**O(1)**, as we use a constant amount of additional space
# Code
```cpp []
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
         int flag=0;
        int prev=0;
        int curr=1;
        int ans=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                curr++;
            }
            else{
                prev=curr;
                curr=1;
            }
            ans=max(ans,max(curr/2,min(prev,curr)));
        }
        return ans;
    }
};
```
```javascript []
class Solution {
    maxIncreasingSubarrays(nums) {
        let prev = 0;
        let curr = 1;
        let ans = 0;

        for (let i = 1; i < nums.length; i++) {
            if (nums[i - 1] < nums[i]) {
                curr++;
            } else {
                prev = curr;
                curr = 1;
            }
            ans = Math.max(ans, Math.max(Math.floor(curr / 2), Math.min(prev, curr)));
        }
        
        return ans;
    }
}

```
```python []
class Solution:
    def maxIncreasingSubarrays(self, nums):
        prev = 0
        curr = 1
        ans = 0

        for i in range(1, len(nums)):
            if nums[i - 1] < nums[i]:
                curr += 1
            else:
                prev = curr
                curr = 1
            ans = max(ans, max(curr // 2, min(prev, curr)))
        
        return ans
```
```java []
class Solution {
    public int maxIncreasingSubarrays(int[] nums) {
        int prev = 0;
        int curr = 1;
        int ans = 0;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] < nums[i]) {
                curr++;
            } else {
                prev = curr;
                curr = 1;
            }
            ans = Math.max(ans, Math.max(curr / 2, Math.min(prev, curr)));
        }
        
        return ans;
    }
}
```


</details>
