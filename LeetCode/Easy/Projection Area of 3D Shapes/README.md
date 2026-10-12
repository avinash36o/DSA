# Projection Area of 3D Shapes

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | October 12, 2026 |
| **Tags** | Array, Math, Geometry, Matrix |
| **Link** | [View Problem](https://leetcode.com/problems/projection-area-of-3d-shapes/) |
| **Runtime** | 0 ms |
| **Memory** | 12.8 MB |

## Problem Description

<p>You are given an <code>n x n</code> <code>grid</code> where we place some <code>1 x 1 x 1</code> cubes that are axis-aligned with the <code>x</code>, <code>y</code>, and <code>z</code> axes.</p>

<p>Each value <code>v = grid[i][j]</code> represents a tower of <code>v</code> cubes placed on top of the cell <code>(i, j)</code>.</p>

<p>We view the projection of these cubes onto the <code>xy</code>, <code>yz</code>, and <code>zx</code> planes.</p>

<p>A <strong>projection</strong> is like a shadow, that maps our <strong>3-dimensional</strong> figure to a <strong>2-dimensional</strong> plane. We are viewing the "shadow" when looking at the cubes from the top, the front, and the side.</p>

<p>Return <em>the total area of all three projections</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/02/shadow.png" style="width: 800px; height: 214px;">
<pre><strong>Input:</strong> grid = [[1,2],[3,4]]
<strong>Output:</strong> 17
<strong>Explanation:</strong> Here are the three projections ("shadows") of the shape made with each axis-aligned plane.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[2]]
<strong>Output:</strong> 5
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> grid = [[1,0],[0,2]]
<strong>Output:</strong> 8
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == grid.length == grid[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 50</code></li>
	<li><code>0 &lt;= grid[i][j] &lt;= 50</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Simple c++ approach 99%  time beat 97% space
**Author**: [@srivastavaanshuman33](https://leetcode.com/srivastavaanshuman33/)
**Upvotes**: 4 👍
**Link**: [View Original Post](https://leetcode.com/problems/projection-area-of-3d-shapes/solutions/349560/)

---

The problem can be thought as counting squares with projected view of shapes on all three planes
xy, yz, and xz
	Now the idea is to sum up the square from all three views as you know on seeing from side we will only see the max_height block in its projection and a n*n square view from top
	sum it al and you get it!!!!!
```
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int N=grid.size();
        int sum=0;                                                                                         //global sum
		// ========View from x axis ===============//
        for(int i=0;i<N;i++)
        {
            int max=*max_element(grid[i].begin(),grid[i].end());            //find max element in a row
            sum+=max;                                                                          //add that to sum
        }
        //==========View from y-axis==========//
        int k=0;
        for(int i=0;i<N;i++){
            int maxel=0;
            for(int j=0;j<N;j++){
                if(grid[j][i]==0) k++;                                    //keeps track of places where no block is placed
                maxel=max(maxel,grid[j][i]);                         //maxlen is max element in a column
            }
            sum+=maxel;                                                    //adding maxlen to sum
        
        }
        //========View from z-axis=======//
		sum+=(N*N);                                        //top view has n*n squares
        sum-=k;                                               //excluding where no squares are there
		
        return sum;
    }
};
```
===PLEASE UPVOTE IF YOU LIKE IT==========

</details>
