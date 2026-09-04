# Count the Number of Good Nodes

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 4, 2026 |
| **Tags** | Tree, Depth-First Search |
| **Link** | [View Problem](https://leetcode.com/problems/count-the-number-of-good-nodes/) |
| **Runtime** | 1231 ms |
| **Memory** | 476.6 MB |

## Approach

make adj list and make dfs. dfs will give the size of curr node and also tell if it is a good node

## Problem Description

<p>There is an <strong>undirected</strong> tree with <code>n</code> nodes labeled from <code>0</code> to <code>n - 1</code>, and rooted at node <code>0</code>. You are given a 2D integer array <code>edges</code> of length <code>n - 1</code>, where <code>edges[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that there is an edge between nodes <code>a<sub>i</sub></code> and <code>b<sub>i</sub></code> in the tree.</p>

<p>A node is <strong>good</strong> if all the <span data-keyword="subtree" class=" cursor-pointer relative text-dark-blue-s text-sm"><button type="button" aria-haspopup="dialog" aria-expanded="false" aria-controls="radix-_r_t_" data-state="closed" class="">subtrees</button></span> rooted at its children have the same size.</p>

<p>Return the number of <strong>good</strong> nodes in the given tree.</p>

<p>A <strong>subtree</strong> of <code>treeName</code> is a tree consisting of a node in <code>treeName</code> and all of its descendants.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]</span></p>

<p><strong>Output:</strong> <span class="example-io">7</span></p>

<p><strong>Explanation:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/05/26/tree1.png" style="width: 360px; height: 158px;">
<p>All of the nodes of the given tree are good.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">edges = [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/06/03/screenshot-2024-06-03-193552.png" style="width: 360px; height: 303px;">
<p>There are 6 good nodes in the given tree. They are colored in the image above.</p>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">edges = [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]</span></p>

<p><strong>Output:</strong> <span class="example-io">12</span></p>

<p><strong>Explanation:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/08/08/rob.jpg" style="width: 450px; height: 277px;">
<p>All nodes except node 9 are good.</p>
</div>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>edges.length == n - 1</code></li>
	<li><code>edges[i].length == 2</code></li>
	<li><code>0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; n</code></li>
	<li>The input is generated such that <code>edges</code> represents a valid tree.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: DFS
**Author**: [@fahad84](https://leetcode.com/fahad84/)
**Upvotes**: 26 👍
**Link**: [View Original Post](https://leetcode.com/problems/count-the-number-of-good-nodes/solutions/5619445/)

---

# Approach
1. **Construct the Tree:** Build a bidirectional adjacency list from the edges array.
2. **DFS Traversal:** Perform a depth-first search to calculate the number of children for each node and store these values in the size vector.
3. **Evaluate Good Nodes:** Iterate through all the nodes from ***0** to **n -1*** to determine if all their child nodes have the same size.

    - Consider only the child nodes. If the size of a neighboring node is less than the size of the current node, it indicates that it is a child node.

    - Initialize the previous size variable to negative one. For each child, if the previous size is not negative one and the current child\'s size is different from the previous size, exit the loop. This means the current node is not a good node because its children do not all have the same size.
4. **Return the Result:** Finally, return the total count of good nodes.
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity: $$O(V + E)$$
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: $$O(V + E)$$
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# code
```C++ []
class Solution {
public:
    vector<list<int>> graph;
    int dfs(int curr, int par, vector<int>& size) {
        int sz = 1;
        for(int nbr : graph[curr]){
            if(nbr != par) sz += dfs(nbr, curr, size);
        }
        size[curr] = sz;
        return sz;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        graph.clear();
        graph.resize(n);
        vector<int> size(n, 0);
        for(int i = 0; i < n-1; i++){
            graph[edges[i][1]].push_back(edges[i][0]);
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        dfs(0, -1, size);
        int res = 0;

        for(int i = 0; i < n; i++){
            bool flag = true;
            int prev = -1;
            for(auto nbr : graph[i]) {
                if(size[nbr] < size[i]){
                    if(prev == -1) prev = size[nbr];
                    else if(prev != size[nbr]) {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) res++;
        }

        return res;
    }
};
```
```Java []
class Solution {
    private List<List<Integer>> graph;
    private int[] subtreeSize;

    private int dfs(int curr, int parent) {
        int size = 1;
        for (int nbr : graph.get(curr)) {
            if (nbr != parent) {
                size += dfs(nbr, curr);
            }
        }
        subtreeSize[curr] = size;
        return size;
    }

    public int countGoodNodes(int[][] edges) {
        int n = edges.length + 1;
        graph = new ArrayList<>(n);
        subtreeSize = new int[n];
        
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }

        dfs(0, -1);

        int result = 0;
        for (int i = 0; i < n; i++) {
            boolean isGoodNode = true;
            int previousSize = -1;
            for (int nbr : graph.get(i)) {
                if (subtreeSize[nbr] < subtreeSize[i]) {
                    if (previousSize == -1) {
                        previousSize = subtreeSize[nbr];
                    } else if (previousSize != subtreeSize[nbr]) {
                        isGoodNode = false;
                        break;
                    }
                }
            }
            if (isGoodNode) {
                result++;
            }
        }

        return result;
    }
}
```
```Python3 []
class Solution:
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        def dfs(curr: int, parent: int) -> int:
            size = 1
            for nbr in graph[curr]:
                if nbr != parent:
                    size += dfs(nbr, curr)
            subtree_size[curr] = size
            return size

        n = len(edges) + 1
        graph = defaultdict(list)
        subtree_size = [0] * n

        # Build the graph
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        dfs(0, -1)

        result = 0
        for i in range(n):
            is_good_node = True
            previous_size = -1
            for nbr in graph[i]:
                if subtree_size[nbr] < subtree_size[i]:
                    if previous_size == -1:
                        previous_size = subtree_size[nbr]
                    elif previous_size != subtree_size[nbr]:
                        is_good_node = False
                        break
            if is_good_node:
                result += 1

        return result

```


</details>
