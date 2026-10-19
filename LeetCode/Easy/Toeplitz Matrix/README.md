# Toeplitz Matrix

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | October 20, 2026 |
| **Tags** | Array, Matrix |
| **Link** | [View Problem](https://leetcode.com/problems/toeplitz-matrix/) |
| **Runtime** | 0 ms |
| **Memory** | 20.8 MB |

## Problem Description

<p>Given an <code>m x n</code> <code>matrix</code>, return&nbsp;<em><code>true</code>&nbsp;if the matrix is Toeplitz. Otherwise, return <code>false</code>.</em></p>

<p>A matrix is <strong>Toeplitz</strong> if every diagonal from top-left to bottom-right has the same elements.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/ex1.jpg" style="width: 322px; height: 242px;">
<pre><strong>Input:</strong> matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
<strong>Output:</strong> true
<strong>Explanation:</strong>
In the above grid, the&nbsp;diagonals are:
"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
In each diagonal all elements are the same, so the answer is True.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/ex2.jpg" style="width: 162px; height: 162px;">
<pre><strong>Input:</strong> matrix = [[1,2],[2,2]]
<strong>Output:</strong> false
<strong>Explanation:</strong>
The diagonal "[1, 2]" has different elements.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 20</code></li>
	<li><code>0 &lt;= matrix[i][j] &lt;= 99</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>What if the <code>matrix</code> is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?</li>
	<li>What if the <code>matrix</code> is so large that you can only load up a partial row into the memory at once?</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: C++ solution
**Author**: [@OleksaM](https://leetcode.com/OleksaM/)
**Upvotes**: 17 👍
**Link**: [View Original Post](https://leetcode.com/problems/toeplitz-matrix/solutions/697246/)

---

```
bool isToeplitzMatrix(vector<vector<int>>& matrix) {
	for (int i = 0; i < matrix.size() - 1; i++) {
		for (int j = 0;  j < matrix[0].size() - 1; j++) {
			if (matrix[i][j] != matrix[i + 1][j + 1])
				return false;
		}
	}
	return true;
}
```


</details>
