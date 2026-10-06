# Count Negative Numbers in a Sorted Matrix

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | October 6, 2026 |
| **Tags** | Array, Binary Search, Matrix |
| **Link** | [View Problem](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/) |
| **Runtime** | 0 ms |
| **Memory** | 14.1 MB |

## Problem Description

<p>Given a <code>m x n</code> matrix <code>grid</code> which is sorted in non-increasing order both row-wise and column-wise, return <em>the number of <strong>negative</strong> numbers in</em> <code>grid</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
<strong>Output:</strong> 8
<strong>Explanation:</strong> There are 8 negatives number in the matrix.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[3,2],[1,0]]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 100</code></li>
	<li><code>-100 &lt;= grid[i][j] &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you find an <code>O(n + m)</code> solution?

##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: C++ | Binary Search | O ( n + m )
**Author**: [@Saa27](https://leetcode.com/Saa27/)
**Upvotes**: 74 👍
**Link**: [View Original Post](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/solutions/1098576/)

---

```
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int i=m-1;
        int j=0;
		// to start from the grid[m-1][0] position
        int count=0;
        
        while(i>=0 && i<m && j>=0 && j<n){
            if(grid[i][j] < 0){
                count = count + (n-j); //when the first occurrence of a number in a row is -ve, all following numbers will be -ve. So, add their count.
                i=i-1; //then move to the above row
            }
            else{
                j=j+1; //else move to the right (i.e. to the next column)
            }
                
        }       
        
        return count;
    }
};
```

</details>
