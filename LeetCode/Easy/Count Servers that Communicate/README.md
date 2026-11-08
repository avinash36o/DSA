# Count Servers that Communicate

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | November 8, 2026 |
| **Tags** | Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix, Counting |
| **Link** | [View Problem](https://leetcode.com/problems/count-servers-that-communicate/) |
| **Runtime** | 2 ms |
| **Memory** | 26.6 MB |

## Problem Description

<p>You are given a map of a server center, represented as a <code>m * n</code> integer matrix&nbsp;<code>grid</code>, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.<br>
<br>
Return the number of servers&nbsp;that communicate with any other server.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/11/14/untitled-diagram-6.jpg" style="width: 202px; height: 203px;"></p>

<pre><strong>Input:</strong> grid = [[1,0],[0,1]]
<strong>Output:</strong> 0
<b>Explanation:</b>&nbsp;No servers can communicate with others.</pre>

<p><strong class="example">Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2019/11/13/untitled-diagram-4.jpg" style="width: 203px; height: 203px;"></strong></p>

<pre><strong>Input:</strong> grid = [[1,0],[1,1]]
<strong>Output:</strong> 3
<b>Explanation:</b>&nbsp;All three servers can communicate with at least one other server.
</pre>

<p><strong class="example">Example 3:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2019/11/14/untitled-diagram-1-3.jpg" style="width: 443px; height: 443px;"></p>

<pre><strong>Input:</strong> grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
<strong>Output:</strong> 4
<b>Explanation:</b>&nbsp;The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m &lt;= 250</code></li>
	<li><code>1 &lt;= n &lt;= 250</code></li>
	<li><code>grid[i][j] == 0 or 1</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: DSU || Clear Explanation
**Author**: [@crytondre](https://leetcode.com/crytondre/)
**Upvotes**: 7 👍
**Link**: [View Original Post](https://leetcode.com/problems/count-servers-that-communicate/solutions/3892912/)

---

# Approach
<!-- Describe your approach to solving the problem. -->
1. **DisjointSet Class:**
This class represents a disjoint set data structure, which is used to maintain and perform operations on disjoint sets.

    - **Constructor (DisjointSet(int n))**

        This constructor initializes the data structures for the disjoint set. It takes an integer n which represents the total number of nodes in the disjoint set. The constructor does the following:

            - Resizes the parent and size vectors to accommodate n+1 elements.
            - Initializes each node as its own parent.
            - Initializes the size of each node to 1, indicating that each node is initially in a set by itself.
    - **findUPar(int node) Method**

        This method implements the find operation in the disjoint set data structure. It recursively searches for the ultimate parent (representative) of a given node node. Additionally, it employs path compression to optimize future queries by updating the parent of each traversed node to the ultimate parent.

    - **unionBySize(int u, int v) Method**

        - This method performs the union operation by size. It takes two node indices u and v and merges the sets to which they belong. It does the following:

        - Finds the ultimate parents of nodes u and v using the findUPar method.
        - Checks if the ultimate parents are the same. If they are, it means the nodes are already in the same set, and no action is needed.
        - If the ultimate parent of u has a smaller size compared to the ultimate parent of v, it swaps u and v to ensure that the larger set remains the parent.
        - It then updates the parent of u to v and updates the size of v by adding the size of u. It also sets the size of u to 0 to mark it as no longer a root.
2. **Solution Class:**
This class contains the implementation of the solution for the LeetCode problem.

    - **countServers(vector<vector<int>>& grid) Method**

        This method takes a 2D grid as input and returns the count of servers that are connected in the grid. The grid is represented by a binary matrix where 1 represents a server and 0 represents an empty cell.

        The method follows the following steps:

        - Initialize variables n and m to the number of rows and columns in the grid, respectively.
        - Create a DisjointSet object ds with a capacity of n * m nodes.
        - Iterate through the grid to find servers and perform union operations:
        - If a server is found (grid[row][col] == 1), calculate the index cellInd for the current cell.
        - Iterate through the cells in the current row to identify connected servers and perform union operations.
        - Iterate through the cells in the current column to identify connected servers and perform union operations.
        - Calculate the count of connected servers using the size array of the DisjointSet object.
        - Return the total count of connected servers.

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
    O(n * \u03B1(n))
where \u03B1 is a constant

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
    O(n)

# Code
```
class DisjointSet {
    public : 
        vector<int> parent,size;
        DisjointSet(int n) {
            parent.resize(n+1);
            size.resize(n+1);

            for(int i=0;i<=n;i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node) {
            if(parent[node] == node)
                return node;

            return parent[node] = findUPar(parent[node]);
        }


        void unionBySize(int u,int v) {
            int ultU = findUPar(u);
            int ultV = findUPar(v);

            if(ultU == ultV)
                return;

            if(size[ultU] < size[ultV]) {
                parent[ultU] = ultV;
                size[ultV] += size[ultU];
                size[ultU] = 0;
            }
            else {
            parent[ultV] = ultU;
            size[ultU] += size[ultV];  // Fix: Update size of the new root node
            size[ultV] = 0;
        }
        }
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxRow = n-1,maxCol = m-1;

        DisjointSet ds(n*m);

        for(int row=0;row<n;row++) {
            for(int col=0;col<m;col++) {
                if(grid[row][col] == 1) {
                    int cellInd = row*m + col;

                    while(col < m) {
                        if(grid[row][col] == 1) {
                            int neighCellInd = row*m + col;

                            ds.unionBySize(cellInd,neighCellInd);
                        }
                        col++;
                    }
                }
            }
        }


        for(int col = 0;col<m;col++) {
            for(int row = 0;row<n;row++) {
                if(grid[row][col] == 1) {
                    int cellInd = row*m + col;
                    while(row < n) {
                        if(grid[row][col] == 1) {
                            int neighCellInd = row*m + col;
                            ds.unionBySize(cellInd,neighCellInd);
                        }
                        row++;
                    }
                }
            }
        }

        int count = 0;

        for(int i=0;i<=(n*m);i++) {
            if(ds.size[i] > 1) {
                count += ds.size[i];
            }
        }


        return count;
    }
};
```

![upvote_CAT.webp](https://assets.leetcode.com/users/images/a8f8cb19-4401-48b0-bc5f-ecb3baea11ff_1691721538.6728802.webp)


</details>
