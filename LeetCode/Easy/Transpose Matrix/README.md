# Transpose Matrix

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | October 6, 2026 |
| **Tags** | Array, Matrix, Simulation |
| **Link** | [View Problem](https://leetcode.com/problems/transpose-matrix/) |
| **Runtime** | 4 ms |
| **Memory** | 15.2 MB |

## Problem Description

<p>Given a 2D integer array <code>matrix</code>, return <em>the <strong>transpose</strong> of</em> <code>matrix</code>.</p>

<p>The <strong>transpose</strong> of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.</p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/02/10/hint_transpose.png" style="width: 600px; height: 197px;"></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [[1,4,7],[2,5,8],[3,6,9]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> matrix = [[1,2,3],[4,5,6]]
<strong>Output:</strong> [[1,4],[2,5],[3,6]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 1000</code></li>
	<li><code>1 &lt;= m * n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= matrix[i][j] &lt;= 10<sup>9</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅ Beats 100% - Explained with [ Video ] - C++/Java/Python/JS - Visualized
**Author**: [@lancertech6](https://leetcode.com/lancertech6/)
**Upvotes**: 83 👍
**Link**: [View Original Post](https://leetcode.com/problems/transpose-matrix/solutions/4384031/)

---

![Screenshot 2023-12-10 062820.png](https://assets.leetcode.com/users/images/8a732cba-8e5e-4ea5-a013-aacee0beafde_1702170049.7675757.png)

# YouTube Video Explanation:

[https://youtu.be/P9dFhd_003k](https://youtu.be/P9dFhd_003k)
<!-- **If you want a video for this question please write in the comments** -->

**\uD83D\uDD25 Please like, share, and subscribe to support our channel\'s mission of making complex concepts easy to understand.**

Subscribe Link: https://www.youtube.com/@leetlogics/?sub_confirmation=1

*Subscribe Goal: 800 Subscribers*
*Current Subscribers: 703*

---

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The transpose of a matrix can be obtained by swapping its rows and columns. We iterate through each element of the original matrix and fill the corresponding position in the transposed matrix.

# Approach
<!-- Describe your approach to solving the problem. -->
1. Determine the number of rows (`row`) and columns (`col`) in the original matrix.
2. Create a new matrix `arr` with dimensions `col x row`.
3. Iterate through each element of the original matrix, assigning it to the corresponding position in the transposed matrix.
4. Return the transposed matrix.

# Complexity
- Time Complexity: `O(m * n)` where m and n are the number of rows and columns in the matrix.
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space Complexity: `O(m * n)` for the transposed matrix.
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```java []
class Solution {
    public int[][] transpose(int[][] matrix) {
        int row=matrix.length;
        int col=matrix[0].length;
        int arr[][]=new int[col][row];
        for(int i=0;i<col;i++)
        {
            for(int j=0;j<row;j++)
            {
            arr[i][j]=matrix[j][i];
            }
        }
        return arr;
    }
}
```
```C++ []
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> result(col, vector<int>(row, 0));
        
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < row; ++j) {
                result[i][j] = matrix[j][i];
            }
        }
        
        return result;
    }
};
```
```Python []
class Solution(object):
    def transpose(self, matrix):
        row = len(matrix)
        col = len(matrix[0])
        result = [[0] * row for _ in range(col)]
        
        for i in range(col):
            for j in range(row):
                result[i][j] = matrix[j][i]
                
        return result
        
```
```JavaScript []
/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var transpose = function(matrix) {
    let row = matrix.length;
    let col = matrix[0].length;
    let result = Array.from({ length: col }, () => Array(row).fill(0));
    
    for (let i = 0; i < col; ++i) {
        for (let j = 0; j < row; ++j) {
            result[i][j] = matrix[j][i];
        }
    }
    
    return result;
};
```
![upvote.png](https://assets.leetcode.com/users/images/e33517a5-75b3-405d-b135-21f885980b06_1702170146.1217864.png)


</details>
