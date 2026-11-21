# Find All Duplicates in an Array

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | November 21, 2026 |
| **Tags** | Array, Hash Table, Sorting |
| **Link** | [View Problem](https://leetcode.com/problems/find-all-duplicates-in-an-array/) |
| **Runtime** | 3 ms |
| **Memory** | 48.5 MB |

## Problem Description

<p>Given an integer array <code>nums</code> of length <code>n</code> where all the integers of <code>nums</code> are in the range <code>[1, n]</code> and each integer appears <strong>at most</strong> <strong>twice</strong>, return <em>an array of all the integers that appears <strong>twice</strong></em>.</p>

<p>You must write an algorithm that runs in <code>O(n)</code> time and uses only <em>constant</em> auxiliary space, excluding the space needed to store the output</p>

<p>&nbsp;</p>
<p><span class="float-right -my-0.5 ml-2 inline-flex select-none items-center" data-example-lang-controls=""><span role="group" class="inline-flex h-6 items-center rounded-sd-md bg-sd-muted p-0.5" data-example-lang-toggle=""><button type="button" aria-pressed="true" class="h-5 max-w-[10rem] truncate whitespace-nowrap rounded-sd-sm border px-2 text-xs font-normal leading-none border-sd-border bg-sd-background text-sd-foreground">Original</button><button type="button" aria-pressed="false" class="h-5 max-w-[10rem] truncate whitespace-nowrap rounded-sd-sm border px-2 text-xs font-normal leading-none border-transparent text-sd-muted-foreground hover:text-sd-foreground">C++</button></span></span><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [4,3,2,7,8,2,3,1]
<strong>Output:</strong> [2,3]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,2]
<strong>Output:</strong> [1]
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> []
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= n</code></li>
	<li>Each element in <code>nums</code> appears <strong>once</strong> or <strong>twice</strong>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Utilizing Integer Range for Duplicate Identification
**Author**: [@CS_MONKS](https://leetcode.com/CS_MONKS/)
**Upvotes**: 281 👍
**Link**: [View Original Post](https://leetcode.com/problems/find-all-duplicates-in-an-array/solutions/4921063/)

---


"Happy Holi to all my friends! Keep coding with colorful solutions!" \uD83C\uDFA8\uD83C\uDF1F
# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
To solve this problem in O(n) time and constant extra space, we can utilize the fact that all integers in the array are in the range [1, n] and each integer appears once or twice. We can iterate through the array and use each element as an index to mark the corresponding element as negative. If we encounter an element that is already negative, it means we have seen it before and it\'s a duplicate.
# Approach
<!-- Describe your approach to solving the problem. -->
1. Initialize an empty vector ans to store the duplicates.
2. Iterate through the array nums.
3. For each element nums[i], take its absolute value x.
4. Check if nums[x-1] is negative. 
5. If it is, then x is a  duplicate, so add it to ans.
6. Otherwise, mark nums[x-1] as negative.
7. Return ans.
# Complexity
- Time complexity:O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(k)
       max value of k = n/2
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```c++ []
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n=size(nums);
        for(int i=0;i<n;i++){
            int x=abs(nums[i]);
            if(nums[x-1]<0){
                
                ans.push_back(x);
            }
            nums[x-1]*=-1;
        }
        return ans;
    }
};
```
```javascript []
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    const ans = [];
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        const x = Math.abs(nums[i]);
        if (nums[x - 1] < 0) {
            ans.push(x);
        }
        nums[x - 1] *= -1;
    }
    return ans;
};

```
```python3 []
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ans =[]
        n=len(nums)
        for x in nums:
            x = abs(x)
            if nums[x-1]<0:
                ans.append(x)
            nums[x-1] *= -1
        return ans

```
```java []

class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int x = Math.abs(nums[i]);
            if (nums[x - 1] < 0) {
                ans.add(x);
            }
            nums[x - 1] *= -1;
        }
        return ans;
    }
}

```

![upvote.jpg](https://assets.leetcode.com/users/images/ab7fc2cc-4fff-4015-8306-db40c5b268f0_1711329538.5499132.jpeg)




</details>
